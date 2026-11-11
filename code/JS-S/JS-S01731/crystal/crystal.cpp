#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],b[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i]-a[i-1];
    }
    long long l=1,r=n;
    while(l<r){
        long long mid=(l+r)/2+1,flag=0;
        for(int i=mid;i<=n;i++){
            long long sum=0;
            for(int j=i-mid+1;j<=i;j++){
                sum+=b[i]-b[j];
            }
            if(sum<=m){
                flag=1;
                break;
            }
        }
        if(flag==1){
            l=mid;
        }
        else{
            r=mid-1;
        }

    }
    cout<<l;
    return 0;
}
