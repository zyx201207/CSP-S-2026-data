#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,m,cnt=INT_MIN,a[N];
void dfs(int i,long long ans,int k){
    if(i>n||k==m){
        if(k==m){
            cnt=max(ans,cnt);
            //cout<<ans<<' ';
        }

        return;
    }
    if(k==0){
        dfs(i+1,ans,0);
        ans=a[i];
        dfs(i+1,ans,k+1);
        ans=0;
    }
    else{
        //cout<<ans<<' '<<i<<' '<<k<<'\n';
        dfs(i+1,ans,k);
        ans=ans&a[i];
        dfs(i+1,ans,k+1);

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    cout<<cnt;
return 0;
}

