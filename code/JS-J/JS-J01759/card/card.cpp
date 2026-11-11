#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005];
bool vis[300005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(st.top()!=a[j])
                    st.pop();
            }
            else{
                st.push(a[j]);
                vis[a[j]]=1;
            }
        }
        while(!st.empty()){
            sum[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
