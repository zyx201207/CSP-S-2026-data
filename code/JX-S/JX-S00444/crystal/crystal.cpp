#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+3;
int a[N],f[N];
int n,m,mid=0,ans=0;
void dfs(int x,int l,int sum,int la){
    sum++;
    if(l<a[la]-a[x-1]||x<1){
        ans=max(ans,sum);
        return;
    }
    for(int i=x-1;i>=1;i--){
        dfs(i,l+a[i]-a[la],sum,la);
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)dfs(i,m,0,i);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
