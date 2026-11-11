#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],b[500005], _[500005];
int cs;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    int top=0;
    for(int i=1;i<=n;i++){
        cin>>_[i];
    }
    sort(_+1,_+1+n);
    cs=_[1];
    if(cs==0)a[++top]=0,b[top]=1;
    else a[++top]=cs,b[top]=1;
    for(int i=2;i<=n;i++){
        cs=_[i];
        if(cs!=a[top]) a[++top]=cs;
        b[top]++;
    }
    for(int i=2;i<=top;i++) ;
    int nmax = 1;
    for(int i=2;i<=top;i++){
        int t=m, ans=b[i];
        for(int j=i-1;j>=1;j--){
            if(t-(b[j]*(a[i]-a[j]))>=0)ans+=b[j],t-=(b[j]*(a[i]-a[j]));
            else ans+=(t/(b[j]*(a[i]-a[j])));
        }
        nmax=max(ans, nmax);
    }
    cout<<nmax;
    return 0;
}
