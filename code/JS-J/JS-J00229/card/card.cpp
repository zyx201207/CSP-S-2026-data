#include<bits/stdc++.h>
using namespace std;
const int M=300005;
const int N=500005;
int a[N],ans[M],n,m;
bool f[M],judge[M];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(judge,sizeof(judge),0);
        memset(f,sizeof(f),0);
        for(int j=i;j<=n;j++){
            if(f[a[j]]==1){
                while(st.top()!=a[j]){
                    st.pop();
                }
            }
            else{
                f[a[j]]=1;
                st.push(a[j]);
            }
        }
        while(!st.empty()){
            int to=st.top();
            judge[to]=1;
            st.pop();
        }
        for(int k=1;k<=m;k++){
            if(judge[k]) ans[k]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
