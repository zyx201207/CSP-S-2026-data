#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],n,m,d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll maxd=0,cnt=0,l=1;
    for(int r=1;r<=n;r++){
        while((a[r]-a[r-1])*(r-l)+cnt>m){
            cnt-=(a[r-1]-a[l]);
            l++;
        }
        cnt+=(a[r]-a[r-1])*(r-l);
        maxd=max(maxd,r-l+1);
    }
    cout<<maxd;
}
