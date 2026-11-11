#include<bits/stdc++.h>
#define EQ ==
using namespace std;
typedef long long ll;
const int N=500500;
int n,ans=0;
ll m,a[N];
int main(){
    cin.tie(0)->ios::sync_with_stdio;
    cout.tie(0)->ios::sync_with_stdio;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int t=1;t<=n;t++){
        cin>>a[t];
    }
    sort(a+1,a+n+1);
    int l=1,r=0;ll now=0,cha=0;
    for(int t=1;t<=n;t++){
        if(t<n&&a[t+1] EQ a[t]){
            continue;
        }
        int num=r-l+1;r=t;
        now+=1ll*num*cha;
        while(now>m){
            now-=(a[t]-a[l]);l++;
        }
        cha=a[t+1]-a[t];
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}