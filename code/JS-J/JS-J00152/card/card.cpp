#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,top;
int a[500010];
int ap[500010];
int ans[500010];
stack<int> st;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        top=0;
        memset(ap,0,sizeof(ap));
        for(int j=i;j<=n;j++){
            if(!ap[a[j]]){
                st.push(a[j]);
                ap[a[j]]=1;
            }else{
                while(st.top()!=a[j])ap[st.top()]=0,st.pop();
            }
        }
        for(int j=1;j<=m;j++){
            if(ap[j])ans[j]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}