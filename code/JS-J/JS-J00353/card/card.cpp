#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,ans[300005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<int>st;
        int l=i,vis[m+5]={0};
        while(l<=n){
            if(vis[a[l]]==0){
                st.push(a[l]);
                vis[a[l]]=1;
            }
            else{
                while(st.top()!=a[l]){
                    st.pop();
                }
                while(!st.empty()){
                    ans[st.top()]++;
                    st.pop();
                }
            }
            l++;
        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
