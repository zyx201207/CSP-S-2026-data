#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k;
    int cnt=1,ma=-2e9;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cnt=1;
        k=m;
        for(int j=i-1;j>=1;j--)
        {
            if(k-(a[i]-a[j])>=0){
                k-=(a[i]-a[j]);
                cnt++;
            }
        }
        ma=max(ma,cnt);
    }
    cout<<ma;
    return 0;
}
