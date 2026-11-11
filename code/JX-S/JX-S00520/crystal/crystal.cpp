#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;

ll n,m,a[N],tot[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    tot[1]=0;
    for(int i=2;i<=n;i++){
        ll temp=0;
        for(int j=1;j<i;j++){
            temp+=(a[i]-a[j]);
        }
        tot[i]=temp;
        //cout<<tot[i]<<" ";
    }
    //cout<<"\n";

    ll l=1,r=n,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(tot[mid]<=m){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    //if(m%tot[ans]==0)
    cout<<ans<<"\n";
    //else cout<<max(m%tot[ans],ans-(m%tot[ans]));

    return 0;
}
