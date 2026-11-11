#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN],b[MAXN],l,ans,c[MAXN],d[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    a[0]=a[1];
    b[0]=0;c[0]=0;d[0]=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
            b[i]=a[i]-a[i-1];
            c[i]=b[i]+c[i-1];
            d[i]=d[i-1]+i*b[i];
    }
    l=1;
    for(int i=1;i<=n&&i>=l;i++){
        int j;
        for(j=l;j<=i&&(d[i]-d[j]-j*(c[i]-c[j]))>m;j++);
        l=j;
        ans=max(i-l+1,ans);
    }
    cout<<ans;
    return 0;
}
