#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e5+5;

int n,m,ans;
int a[N];

void dfs(int g,int k,int val){
    if(n-g+1+k<m) return ;
    if(k==m){
        ans=max(ans,val);
        return ;
    }
    if(g>=n+1) return ;

    dfs(g+1,k,val);
    dfs(g+1,k+1,val&a[g]);
}



signed main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=3000){
        for(int i=1;i<=n;i++){
            dfs(i,0,a[i]);
        }

        cout<<ans<<'\n';
    }
    else{
        sort(a+1,a+1+n);
        for(int i=n;i>=1;i--)
            if(i==n-m+1){
                cout<<a[i]<<'\n';
                break;
            }
    }

    return 0;
}
