#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(long long i=1;i<=n;i++){
        long long l=1,r=i,ans=1,mid;
        while(l<=r){
            mid=(l+r)/2;
            long long len=i-mid+1;
            long long k=(len-1)*a[i]-(s[i-1]-s[mid-1]);
            if(k<=m){
                r=mid-1;
                ans=max(ans,len);
            }
            else l=mid+1;
        }
        mx=max(mx,ans);
    }
    cout<<mx;
    return 0;
}
