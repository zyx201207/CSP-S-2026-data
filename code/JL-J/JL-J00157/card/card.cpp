#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[300005],vis[300005];
stack<int>st;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(st.top()!=a[j])vis[st.top()]=0,st.pop();
                vis[st.top()]=0;
                st.pop();
            }
            st.push(a[j]);
            vis[a[j]]=1;
        }
        while(!st.empty()){
            vis[st.top()]=0;
            ans[st.top()]++;
            st.pop();
        }
    }

    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}
