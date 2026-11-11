#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll n,a[500000+10],b[500000+10],m,tmax=-9999999999,tmin=999999999,cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        ll t=m;
        cnt=1;
        //a[i-1]=b[i-1];
        while(t>0&&cnt<=n){
            ll s=a[i+cnt]-a[i];
            if(s>t){
                break;
            }else if(s<0){
                s*=-1;
            }
            t-=s;
            a[i]=a[i+cnt];
            cnt++;
            if(cnt>tmax){
                tmax=cnt;
            }
        }
    }
    cout<<tmax;
    return 0;
}
