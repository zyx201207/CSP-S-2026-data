#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],ans;
void dfs(int t,int step,int idx){
    if(step==0){
        ans=max(ans,t);
        return ;
    }
    for(int i=idx+1;i<=n;i++){
        int x=t&a[i];
        dfs(x,step-1,i);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++)
        dfs(a[i],m-1,i);
    cout<<ans<<endl;
    return 0;
}
