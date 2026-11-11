#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],x[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,ans=0;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(x[n]<2){
        ll cnt=0,sum=(2<<29)-1;
        for(int i=1;i<=n;i++){
            //cout<<x[i];
            if(x[i]==1){
                cnt++;
                sum=(sum&a[i]);
            }
        }
        //cout<<endl<<sum<<endl;
        if(cnt==m&&sum>ans){
            ans=sum;
        }
        x[1]++;
        for(int i=1;i<n;i++){
            if(x[i]>=2){
                x[i]=0;
                x[i+1]++;
            }
            else{
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
