#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int vis[N];
int ans[N];
stack<int> stk;
void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==i)
                while(stk.top()!=a[j])
                    vis[stk.top()]=0,stk.pop();
            else 
                stk.push(a[j]),vis[a[j]]=i;
        }
        while(!stk.empty())
            ans[stk.top()]++,stk.pop();
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return ;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int _77231=1;
    // cin>>_77231;
    while(_77231--)mian();
}