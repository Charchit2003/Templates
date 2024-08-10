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

void binary_lift(vector<int> g[], int p, int v, vector<vi>& dp, vector<int>& level, int l=0){
    // used when we require arbitary ancestor of any node to precompute it we store it in dp impleted using dfs.
    // dp[p][x] = 2^xth parent of pth node, this transition equation is very interesting
   dp[p][0] = v;
   level[p] = l;
    for(int x=1; x<17; x++)
        dp[p][x] = dp[dp[p][x-1]][x-1];

    for(int child: g[p]){
        if(child == v) continue;
        binary_lift(g, child, p, dp, level, l+1);
    }
    // we are leaving the pth node
}



void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<int> g[n+1];


    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        // u--, v--;
        // int c;// cin>>c;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> dp(n+1, vi(17, 0));
    vector<int> level(n+1);
    binary_lift(g, 1, 0, dp, level); /* O(Nlog(N))*/
    //   to find kth parent break it into sum of powers of 2(binary number)
    // to find 3rd parent of 5th node
    int k=5, r =3;
    int node = k, i=0;
    while(r >=i){
        if(r & (1<<i))
            node = dp[node][i];
        i++;
    }
    auto lcs = [&](int a, int b)->int{
        a = (level[a] <= level[b])?a:b;
        b = (level[a] > level[b])?a:b;
        
        int diff = level[b]-level[a];
        // find diffth ancestor of b and store it in b;
        if(b==a) return a;
        for(int i=16; i>=0; i--){
            // if ith ancestor of b and a are same then continue;
            // else change the node to their respective ith ancestor;
        }
        return dp[a][0];
    };


    int a,b; cin>>a>>b;
    cout lcs(a, b) endl;
    cout node endl;

  return;
}
