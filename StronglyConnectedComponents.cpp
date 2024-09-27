// 2 ways, 1st one is easier.
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

int main() {

    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}


// 2nd way is below

void topoSort(int start, vector<int> *edges, vector<int>& topo, vector<bool>& visited) {
	visited[start] = true;
	for (auto i : edges[start]) {
		if (!visited[i]) {
			topoSort(i, edges, topo, visited);
		}
	}
	topo.pb(start);
}
void getComponent(int start, vector<int>* edges, vector<int>& currComponent, vector<bool>& visited) {
	currComponent.pb(start);
	visited[start] = true;
	for (auto i : edges[start]) {
		if (!visited[i]) {
			getComponent(i, edges, currComponent, visited);
		}
	}
}
vector<vector<int>> getSCC(int n, vector<int>* edges, vector<int>* edgesT) {
	vector<bool> visited(n);
	vector<int> topo;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			topoSort(i, edges, topo, visited);
		}
	}
	fill(visited.begin(), visited.end(), false);
	vector<vector<int>> SCC;
	for (int i = topo.size() - 1; i >= 0; i--) {
		if (!visited[topo[i]]) {
			vector<int> comp;
			getComponent(topo[i], edgesT, comp, visited);
			SCC.pb(comp);
		}
	}
	return SCC;
}
void solve() {
	int n, e;
	cin >> n >> e;
	vector<int> *edges = new vector<int>[n];
	vector<int> *edgesT = new vector<int>[n];
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].pb(b - 1);
		edgesT[b - 1].pb(a - 1);
	}
	vector<vector<int>> SCC = getSCC(n, edges, edgesT);
}
