#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=5e5+10;
ll a[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ll j=1,mx=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(j<i)j=i;
        while(j<n&&cnt+(j-i+1)*(a[j+1]-a[j])<=m)cnt+=(j-i+1)*(a[j+1]-a[j]),j++;
        mx=max(mx,j-i+1);
        cnt-=a[j]-a[i];
    }
    cout<<mx;
    return 0;
}
