

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int x=a[2]-a[1];
    ll y=0;
    int i;
    for(i=1;y<=m;y++){
        y+=x*i;
    }
    y-=i*x;
    cout<<i;
    return 0;
}

