#include<bits/stdc++.h>
using namespace std;
long long n,m,f[500010],a[500010],cz[500010],mx=INT_MIN;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    if (m>100000000){
        int s=a[2]-a[1],cnt=0;
        for (int i=1;;i+=s){
            if ((a[i]-a[1])*i*1.0/2>m){
                cout<<cnt;
                return 0;
            }
            cnt++;
        }
    }
    for (int i=2;i<=n;i++) cz[i]=a[i]-a[i-1];
    for (int i=2;i<=n;i++) cz[i]+=cz[i-1];
    for (int i=1;i<=n;i++){
        int czh=0;
        f[i]=1;
        for (int j=i;j>=2;j--){
            if (cz[i]-cz[j-1]>m) break;
            f[i]++;
        }
        mx=max(mx,f[i]);
    }
    cout<<mx;
    return 0;
}
