#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

// Range queries datatype = 1) segment trees 2) Lazy 3) Fenwick 4) Sparse Table 5) Mo's Algo 6) SquareRoot Decomposition.


template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<int> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<int> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, int val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	int val; // may change
	Node1() { // Identity element nodes put in extra.
		val = 0;	// may change
	}
	Node1(int p1) {  // Actual Node leaf Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = l.val + r.val;  // may change
	}
};

struct Update1 {
	int val; // may change
	Update1(int p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};





template<typename Node, typename Update>
struct LazySGT {
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<int> arr; // type may change
    int n;
    int s;
    LazySGT(int a_len, vector<int> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), false);
        updates.resize(s); fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void pushdown(int index, int start, int end){
        if(lazy[index]){
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(int index, int start, int end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this
        if(start > right || end < left)
            return;
        if(start >= left && end <= right){
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, int val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};
/*
struct Node1 {
    int val; // may change
    Node1() { // Identity element
        val = 0;    // may change
    }
    Node1(int p1) {  // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val = l.val + r.val;  // may change
    }
};

struct Update1 {
    int val; // may change
    Update1(){ // Identity update
        val = 0;
    }
    Update1(int val1) { // Actual Update
        val = val1;
    }
    void apply(Node1 &a, int start, int end) { // apply update to given node
        a.val = val * (end - start + 1); // may change
    }
    void combine(Update1& new_update, int start, int end){
        val = new_update.val;
    }
};
*/


// There are three seg Trees, 1) Org 2) Lazy(Bool)->if any changes left 3) Update -> what is the change if it is left.
// You always keep your current node updated but if you want to traverse down then pushdown its effect.

// If you need to operate 2 segment trees in one generic code, create two more structs, 
// Node2 and Update2 and make changes in that according.



struct FenwickTree{
    int n;
    vector<int>bit;

    FenwickTree(vector<int> &a) :n(a.size()), bit(n+1){
        for(int i=0; i<n; i++) make_update(i, a[i]);
    }

    void make_update(int i, int x){
        for(i++; i<=n; i += (i&(-i))) bit[i] += x;
    }
    
    int sum(int i){
        int s=0;
        for(i++; i>0; i -= (i&(-i))) s += bit[i];
        return s;
    }

    int make_query(int l, int r){
        return sum(r) - sum(l-1);
    }

};

// Fenwick Tree or Binary Indexed Trees (BIT) for point update and range queries.
// An dynamic form for prefix sums array, which builds in O(nlog(n)), update,query in O(log(n)), beautiful way to break an array
// which makes it easier to code and access and update the queries.

struct FenwickTree2D{
    int n, m;
    vector<vector<int>> bit;

    FenwickTree2D(vector<vector<int>> &a) :n(a.size()), m(a[0].size()), bit(n+1, vector<int>(m+1)){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) make_update(i, j, a[i][j]);
        }
    }

    void make_update(int i, int j, int x){
        for(i++; i<=n; i += (i&(-i))){
            for(j++; j<=m; j+= (j&(-j))) bit[i][j] += x;
        }
    }

    int sum(int i, int j){
        int s=0;
        for(i++; i>0; i -= (i&(-i))){
            for(j++; j>0; j -= (j&(-j))) s += bit[i][j];
        }
        return s;
    }

    int make_query(int l1, int r1, int l2, int r2){
        return sum(l2, r2) - sum(l1, r2) - sum(l2, r1) + sum(l1, r1);
    }

};



struct SparseTable{
    int n, LOG;
    vector<vector<int>> table;

    int merge(int x, int y){
        return min(x, y);
    }

    SparseTable(vector<int>& a): n(a.size()), LOG(__lg(n)), table(n, vector<int>(LOG +1, -1)){
        for(int j=0; j<=LOG; j++){
            for(int i=0; i<= n- (1<<j); i++) {
                if(j==0) table[i][j] = a[i];
                else table[i][j] = merge(table[i][j-1], table[i + (1<<(j-1))][j-1]);
            }
        }
    }

    int make_query(int l, int r){
        int j= __lg(r-l+1);
        return merge(table[l][j], table[r-(1<<j)+1][j]);
    }

};

// Spare Table is only used for range queries (immutable array), it gives answer of query in o(1), with O(n^2) space for only idmepotent function
// idempotent function include functions like min, max, and, or, 






signed main(){
    int n; cin>>n;
    vector<int> arr(n, 1);
    // SegTree<Node1, Update1> seg = SegTree<Node1, Update1>(n, arr);
    // seg.make_update(4, 9);
    // cout << seg.make_query(2, 4).val << endl;

    // LazySGT<Node1, Update1> lazy = LazySGT<Node1, Update1>(n, arr);

    // FenwickTree bit = FenwickTree(arr);
    // bit.make_update(5, 10);
    // cout<<bit.make_query(0, 5)<<endl;

    SparseTable sp = SparseTable(arr);
    cout <<sp.make_query(2, 5)<<endl;


    return 0;
}
