// O(VlogV + ElogV)
// Single Source Shortest Path

void Dijkstra(int s, int n, vector<int> &dist, vector<int> &parent, vector<pair<int, int>> *adj) {
	dist.assign(n, INF);
	parent.assign(n, -1);
	dist[s] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	while (!q.empty()) {
		pair<int, int> here = q.top();
		q.pop();
		int v = here.ss;
		int d_v = here.ff;
		if (d_v != dist[v])
			continue;
		for (auto edge : adj[v]) {
			if (dist[v] + edge.ss < dist[edge.ff]) {
				dist[edge.ff] = dist[v] + edge.ss;
				parent[edge.ff] = v;
				q.push({dist[edge.ff], edge.ff});
			}
		}
	}
}
void BellmanFord(int n, int src, vector<pair<int, int>> *edges, vector<int>& dist, set<int>& negCycle) {
	fill(all(dist), INF);
	dist[src] = 0;
	vector<pair<int, pair<int, int>>> e;
	for (int i = 0; i < n; i++) {
		for (auto j : edges[i]) {
			e.pb({j.ss, {i, j.ff}});
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (auto j : e) {
			dist[j.ss.ss] = min(dist[j.ss.ss], dist[j.ss.ff] + j.ff);
		}
	}
	//checking negative cycle
	for (int i = 0; i < n; i++) {
		for (auto j : e) {
			if (dist[j.ss.ss] > dist[j.ss.ff] + j.ff) {
				dist[j.ss.ss] = dist[j.ss.ff] + j.ff;
				negCycle.insert(j.ss.ss);
			}
		}
	}
}

struct dsu{
    vector<int> parent, size, rank;
 
    dsu(int n){
        for(int i=0;i<=n; i++){
            parent.pb(i);
            size.pb(1);
            rank.pb(0);
        }
    }

    int find_par(int node){
        if(parent[node]==node) return node;
        return parent[node]=find_par(parent[node]); // Path Compression
    }

    void union_size(int u, int v){
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv) return;
        // attach lower size tree to higher
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    return;
    }
    
    void union_rank(int u, int v){
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv) return;
        // attach lower size tree to higher
        if(rank[pu] == rank[pv]){
            parent[pu]=pv;
            rank[pu]++;
        }else if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }else{
            parent[pv]= pu;
        }
    return;
    }
 
    
};
 

map<int, pair<int, int>> m;
int t =0;

void dfs(vector<int> g[], int p, int v){

    // we are at pth node
    m[p].ff = t;
    t++;
    for(int child: g[p]){
        if(child == v) continue;
        dfs(g, child, p);
    }
    m[p].ss = t;
    t++;
    // we are leaving the pth node
   
}

void bfs(vector<int> g[], int root){

    queue<pair<int, int>> q;
    q.push({root,0});
    while(!q.empty()){
        // you are at the node
        int node = q.front().ff;
        int par = q.front().ss;
        q.pop();
        cout node gap;
        for(auto child:g[node]){
            if(child == par) continue;
            q.push({child, node});
        }
        // you are leavnig the node
    }
}

int kruskal(vector<pair<int, int>> g[], int n){
    vector<vi> edges;
    int sum =0 ;
    for(int i=1; i<=n; i++){
        for(auto node:g[i]){
            edges.push_back({node.ss, i, node.ff});
        }
    }
    sort(all(edges));
    dsu d(n);
    for(auto it:edges){
        int u = it[1], v = it[2], w = it[0];
        if(d.find_par(u)!=d.find_par(v)){
            sum += w;
            d.union_rank(u,v);
            // can get the data regarding u v and w
        }
    }
    return sum;
}
int prim(vector<pair<int, int>> g[], int n){
    priority_queue<vector<int>> pq;
	vector<bool> vis(n+1, 0);
    int sum =0;
	pq.push({0, 1, 0});
	while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if(vis[top[1]]) continue;
        vis[top[1]] = 1;
        sum += top[0];
        for(auto x: g[top[1]]){
            if(!vis[x.ff]){
                pq.push({-x.ss, x.ff, top[1]});
            }
        }
    }
    return sum;
}
void toposort(vector<pair<int, int>> g[], vector<bool>& vis, vector<int>& indeg, vector<int>&topo, int node){
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while(!q.size()){
        int t = q.front();
        q.pop();
        topo.pb(t);
        for(auto x:g[t]){
            indeg[x.ff]--;
            if(indeg[x.ff]==0 || vis[x.ff]==0){
                q.push(x.ff);
                vis[x.ff] = 1;
            }
        }
    }
}

//   Lambda function for dfs in graphs note you can change void to int in return type
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        for (int v : adj[u])
            if (v != p) {
                col[v] = col[u] ^ 1;
                dfs(v, u, dfs);
            }
    };

    dfs(0, -1, dfs);
