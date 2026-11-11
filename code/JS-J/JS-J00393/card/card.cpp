#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=3010;
int n,m;
int a[N];
bool vis[M];
int ans[M];
void sol1(){
    for(int i=1;i<=n;i++){
        stack<int> st;
        memset(vis,false,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                st.push(a[j]);
                vis[a[j]]=true;
            }
            else{
                while(st.top()!=a[j]){
                    vis[st.top()]=false;
                    st.pop();
                }
            }
        }
        for(int i=1;i<=m;i++)
            if(vis[i])
                ans[i]++;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sol1();
    for(int i=1;i<=m;i++){
        cout<<ans[i];
        if(i!=m) cout<<" ";
    }
    cout<<'\n';
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
