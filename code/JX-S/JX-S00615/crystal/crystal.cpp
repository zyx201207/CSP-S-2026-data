#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    scanf("%d %lld",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int ans=1;
    long long cnt=0;
    for (int l=1,r=1;r<n;l++){
        while (r<n && cnt+(r-l+1)*(a[r+1]-a[r])<=m){
            cnt+=(r-l+1)*(a[r+1]-a[r]);
            r++;
        }
        ans=max(ans,r-l+1);
        cnt-=a[r]-a[l];
    }
    cout<<ans;
    return 0;
}
