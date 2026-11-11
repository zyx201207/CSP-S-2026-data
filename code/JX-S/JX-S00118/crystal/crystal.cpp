#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],sum[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    long long upp=0;
    int l=1,r=1;
    for(;r<=n;r++){
        upp+=(a[r]-a[r-1])*(r-l);
        while(l<=r&&upp>m){
            l++;
            upp-=(a[r]-a[l]);
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
