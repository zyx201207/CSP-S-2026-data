#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1,lst=0;i<=n;i++)
            cin>>x[i],x[i]-=lst,lst+=x[i];
        ll ans=0,ansl=0,l=2,sum=0,l1=0,l2=0,r1=0,r2=0;
        for(ll i=2;i<=n;i++){
            sum+=x[i];
            while(sum>d)sum-=x[l++];
            if(sum+x[i+1]>d||i==n)
                if(l==i)l++;
                else if(l1==0)l1=l,r1=i,ansl=2;
                else if(l2==0)l2=l,r2=i;
                else ans+=(l1-ansl+1)*(i-r2),ansl=l1+1,l1=l2,r1=r2,l2=l,r2=i;
        }
        if(l2!=0)
            ans+=(l1-ansl+1)*(n-r2+1);
        cout<<ans<<"\n";
    }
    return 0;
}
