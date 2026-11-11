#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],an,ans,q,w;
void dfs(int s,int t){
    if(t)
    for(int i=s;i<=n;i++){
    if(t==m)an=a[i];
    else an&=a[i];
    dfs(i+1,t-1);
    if(an>ans)ans=an;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>q)q=a[i];
        if(i==1)w=a[1];
        else w&=a[i];
    }
    if(m==n){
        cout<<w;
        return 0;
    }
    if(m==1){
        cout<<q;
        return 0;
    }
    dfs(1,m);
    cout<<ans;
    return 0;
}
