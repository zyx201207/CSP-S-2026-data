#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+10;
int c,t,a[maxn];
int dfs(int x,int y,int dep,int m){
    if(x==y&&dep!=0){
        return 0;
    }
    if(x==y){
        return 1;
    }
    int sum=0,p=x+1;
    while(a[p]-a[x]<=m&&p<=y){
        sum+=dfs(p,y,dep-1,m);
        p++;
    }
    return sum;
}
void slove(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x=i,y=j,ans=1;
            while(a[y]-a[x]>m){
                int p=x;
                while(a[p]-a[x]<=m)p++;
                if(p==x)break;
                x=p-1;
                ans++;
            }
            if(ans==1)continue;
            if(dfs(i,j,ans,m)==2)sum++;
        }
    }
    cout<<sum<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)slove();
    return 0;
}
