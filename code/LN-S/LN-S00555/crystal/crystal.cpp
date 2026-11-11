#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll cha[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int flag=1,fflag=1,chaa=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i>1)
            if(a[i]!=a[i-1]) flag=0;
        if(i==2) chaa=a[i]-a[i-1];
        if(i>2)
        {
            if(a[i]-a[i-1]!=chaa) fflag=0;
        }
    }
    if(flag==1){
        cout<<n;
        return 0;
    }
    if(fflag==1){
        int ant=1;
        while(m>=ant*chaa)
        {
            m-=ant*chaa;
            ant++;
        }
        cout<<ant;
        return 0;
    }
    sort(a,a+n);
    for(ll i=1;i<n;i++){
        cha[i]=a[i+1]-a[i];
    }
    sort(cha,cha+n);
    int ans=0,head=1,ceng=1;
    if(cha[1]>m)
    {
        cout<<"1";
        return 0;
    }
    while(1){
        if(ceng==1&&cha[head]==0){
            ans+=2;
            head++;
            ceng++;
            continue;
        }
        m-=ceng*cha[ceng];
        if(m<0) break;
        if(ceng==1)
        {
            ans+=2;
            ceng++;
            continue;
        }
        ans++;
        ceng++;
    }
    cout<<ans;
    return 0;
}
