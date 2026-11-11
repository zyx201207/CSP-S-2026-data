#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,t,ans,lst[2000005];
ll a[2000005],d;
ll dfs(int x,int y,bool flg,bool vis){
    if(flg==1){
        if(x>y)return (vis?dfs(y,y,0,1):0);
        if(x==y)return dfs(x+1,lst[x],1,vis);
        if(x==y-1)return lst[x]-y+dfs(lst[x]+1,lst[y],1,(lst[x]-y>0?1:vis));
        return lst[y-1]-lst[y-2]+dfs(lst[y-1]+1,lst[y],1,(lst[y-1]-lst[y-2]>0?1:vis));
    }
    if(x>y)return 0;
    if(x==y)return lst[x]-x+1+dfs(x+1,lst[x],0,vis);
    return lst[y]-lst[y-1]+dfs(lst[y-1],lst[y],0,vis);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];lst[n]=n;
        for(int i=n-1,j=n;i;i--){
            while(a[j]-a[i]>d)j--;
            lst[i]=j;
            ans+=dfs(i+1,lst[i],1,0);
        }
        cout<<ans/2<<'\n';
    }
    return 0;
}