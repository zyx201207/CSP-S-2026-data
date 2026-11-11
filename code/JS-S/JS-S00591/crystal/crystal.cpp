#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n>5000){
        long long k=a[2]-a[1],sum=0;
        for (int i=1;i<=n;i++){
            sum=(((1+i)*i)/2)*k;
            if (sum>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++){
        long long sum=0,nans=1;
        for (int j=i+1;j<=n;j++){
            sum+=(a[j]-a[j-1])*(j-i);
            if (sum>m){
//                    cout<<i<<" "<<j<<" "<<sum<<"\n";
                break;
            }
            nans++;
        }
        if (nans>ans){
            ans=nans;
        }
    }
    cout<<ans;
    return 0;
}
