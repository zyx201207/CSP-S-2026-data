#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    f[1]=0;
    long long fm=0;
    ans=n;
    for(int i=2;i<=n;i++){
        f[i]=a[i]-a[i-1];
        fm+=f[i]*(i-1);
        if(fm>m){
            ans=i-1;
            break;
        }
    }
    cout<<ans;
    return 0;
}