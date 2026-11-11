#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
#define cin fin
#define cout fout
const int N=5e5+5;
int n,m,a[N],s[N],mx;
signed main() {
    // auto st=clock();
    // ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) {
        int b=i;
        for(int S=1<<20;S;S>>=1) {
            int t=b-S;
            if(t<1) continue;
            if(a[i]*(i-t+1)-(s[i]-s[t-1])<=m) b=t;
        }
        mx=max(mx,i-b+1);
    }
    cout<<mx<<'\n';
    // auto ed=clock();
    // cerr<<fixed<<setprecision(3)<<1000.0*(ed-st)/CLOCKS_PER_SEC<<" ms\n";
}