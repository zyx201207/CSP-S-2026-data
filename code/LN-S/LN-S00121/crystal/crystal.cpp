#include <bits/stdc++.h>
using namespace std;
long long n,m,arr[600000],sum=0,cnt=0,brr[600000],maxx=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    brr[1]=0;
    for(long long i=2;i<=n;i++){
        brr[i]=arr[i]-arr[i-1];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            cnt+=brr[j]*(j-i);
            if(cnt>m){
                break;
            }
            maxx=max(maxx,(j-i));
        }
        cnt=brr[i];
    }
    cout<<maxx+1;
    return 0;
}
