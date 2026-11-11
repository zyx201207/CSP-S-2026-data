#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100000010],t,sum,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<1e5){
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
                //cout<<a[i]<<endl;
            ans=0;
            t=m;
            for(int j=i;j>=1;j--){
                if(a[i]==a[j]){
                        ans++;
                        //cout<<ans<<'\n' ;
                }
                else{
                    if(a[j]<a[i]&&t-(a[i]-a[j])>=0){
                        t=t-(a[i]-a[j]);
           //cout<<t<<'\n';
                        ans++;
                    //cout<<ans<<endl;
                    }
                }
            }
        sum=max(sum,ans);
        }
        cout<<sum<<endl;
    }
    else{
        ans=1;
        ll t=a[2]-a[1];
        ll x=1;
        while(m-x*t>=0&&ans<=n){
            m-=x*t;
            x++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
