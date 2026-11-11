#include<bits/stdc++.h>
using namespace std;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
#define int long long
#define cin fin
#define cout fout
int n,m;
int a[500005];
int ps[500005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) ps[i]=ps[i-1]+a[i];
    int l=1;
    int res=0;
    for(int r=1;r<=n;++r){
        while(a[r]*(r-l+1)-ps[r]+ps[l-1]>m) l++;
        res=max(res,r-l+1);
    }
    cout<<res<<"\n";
    return 0;
}
