#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,cnt=INT_MIN;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for(int i=n;i>=1;i--){
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)/2;
            long long ans=a[i]*(i-mid+1)-(b[i]-b[mid-1]);
            if(ans>m){
                l=mid+1;
            }
            else if(ans<=m){
                cnt=max(cnt,i-mid+1);
                r=mid-1;
            }
        }
    }
    cout<<cnt;
    return 0;
}