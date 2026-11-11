#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
long long ans=-1e9;
void dfs(int u,int c,long long sum){
    if(c==m+1){
        ans=max(ans,sum);
        cout<<ans<<" ";
        return;
    }
    long long s0=sum;
    if(c==0){
        sum=a[u];
    }
    else sum=sum&a[u];
    dfs(u+1,c+1,sum);
    sum=s0;
    dfs(u+1,c,sum);
}
int main(){
         freopen("and.in","r",stdin);
         freopen("and.out","w",stdout);
         cin>>n>>m;
         for(int i=1;i<=n;i++)
         {
             cin>>a[i];
         }
         dfs(1,0,0);
         cout<<ans;
         return 0;
}
