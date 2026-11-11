// scc

stack <int> st;
int inque [N + 5], dfn [N + 5], low [N + 5], cnt;
void dfs (int u) {
    for (auto to : G [u]) {
        if (!dfn [to]) {
            dfs (to);
            
        }
    }
}