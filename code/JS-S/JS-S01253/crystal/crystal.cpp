#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans = 0;
vector <int> a;
vector <int> p;

int fd(int l,int r,int xs){
    int mid = (l+r)>>1;
    if (l >= r) return xs-mid;
    //cout<<"%^&"<<mid<<" "<<a[xs-1] * (xs-mid) - (p[xs]-p[mid])<<"\n";
    if (a[xs-1] * (xs-mid) - (p[xs]-p[mid]) <= m)   return fd(l,mid,xs);
    else return fd(mid+1,r,xs);
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    a.resize(n);p.resize(n+1);
    p[0] = 0;
    for (int i = 0;i < n;i++)   cin>>a[i];
    sort(a.begin(),a.end());
    for (int i = 1;i <= n;i++){
        p[i] = p[i-1] + a[i-1];
        ans = max(ans,fd(0,i,i));
    }

    cout<<ans;
}
