#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m;
int a[N+5];
int s[N+5];
int ans=0;
int summ;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    s[0]=0;
    for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    int i=2,j=1;
    while(i<=n){
        if(j==i) ++i;
        else{
            summ=(i-j)*a[i]-(s[i-1]-s[j-1]);
            if(summ<=m){
                ans=max(ans,i-j+1);
                ++i;
            }
            else ++j;
        }
    }
    if(ans==0) ans=1;
    cout<<ans<<'\n';
    return 0;
}