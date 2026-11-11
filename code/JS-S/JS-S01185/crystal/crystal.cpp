#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long a[N];
int main()
{   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=1;
    for(int i=2;i<=n;i++){
        long long sum=1,tmp=0;
        while(i-sum>=1&&a[i]-a[i-sum]+tmp<=m){
            tmp+=a[i]-a[i-sum];
            sum++;
        }
        ans=max(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}
