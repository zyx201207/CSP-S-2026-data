#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
       stack<int> st;
       vector<int> vis(n+1,0);
       for(int j=i;j<=n;j++){
            if(!vis[a[j]]) {
                st.push(a[j]);
                vis[a[j]]++;
            }else{
                while(st.top()!=a[j])
                { vis[st.top()]--;st.pop();
                }

            }
             //for(int j=1;j<=m;j++) cout<<vis[j]<<" ";
       }
       for(int j=1;j<=m;j++) if(vis[j]) ans[j]++;
       //for(int j=1;j<=m;j++) cout<<vis[j]<<" ";
       //cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
/*
i want to in the JS qirendashang
---limoxuan0712 uid:1432277
*/
