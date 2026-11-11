#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    node(int id):ID(id){}
    int ID;
    int depth;
    vector<node*> children;
};
map<int,node*> mapn;
node* get_node(int i)
{
    if(!mapn[i]) mapn[i] = new node(i);
    return mapn[i];
}
node* root;
int ans;
void dfs(node* curr,node* prev)
{
    if(!prev) curr->depth = 0;
    else
    {
        curr->depth = prev->depth + 1;
        ans = curr->depth;
        root = curr;
    }
    for(int i = 0;i < curr->children.size();i++)
    {
        if(curr->children[i] == prev) continue;
        dfs(curr->children[i],curr);
    }
}
int c,t,n,k,u,v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    for(int i = 0;i < t;i++)
    {
        cin >> n >> k;
        ans = 0;
        if(n == k)
        {
            cout << 0 << '\n';
            break;
        }
        for(int i = 0;i < n - 1;i++)
        {
            cin >> u >> v;
            node* nu = get_node(u);
            node* nv = get_node(v);
            nu->children.push_back(nv);
            nv->children.push_back(nu);
        }
        root = mapn[1];
        dfs(root,nullptr);
        dfs(root,nullptr);
        cout << ans / k << '\n';
        for(int i = 1;i <= n;i++) delete mapn[i];
        mapn.clear();
    }
    return 0;
}
