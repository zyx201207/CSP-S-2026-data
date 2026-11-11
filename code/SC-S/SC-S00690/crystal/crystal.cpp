#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[500005],qz[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m,l=1,maxx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
    for(int i=1;i<=n;i++){
        while(a[i]*(i-l+1)-(qz[i]-qz[l-1])>m)l++;
        maxx=max(maxx,i-l+1);
    }
    cout<<maxx<<'\n';
    return 0;
}