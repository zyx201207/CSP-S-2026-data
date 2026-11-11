#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MAXN=5e5+5,INF=0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[MAXN]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mx=0;
    int d=0,s=1;
    for(int i=1;i<=n;i++){
        d+=s*(a[i]-a[i-1]);
        s++;
        while(d>m){
            d-=a[i]-a[i-s+1];
            s--;
        }
        mx=max(mx,s);
    }
    cout<<mx;
}
