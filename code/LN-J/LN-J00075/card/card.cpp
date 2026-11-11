#include<bits/stdc++.h>
using namespace std;

int n,m;
int vis[300010],ans[300010];
int a[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int>st;
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                st.push(a[j]);
                vis[a[j]]=1;
            }else{
                while(1){
                    int x=st.top();
                    if(x==a[j])break;
                    st.pop();
                    vis[x]=0;
                }
            }
        }
        while(!st.empty()){
            int x=st.top();
            st.pop();
            vis[x]=0;
            ans[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

