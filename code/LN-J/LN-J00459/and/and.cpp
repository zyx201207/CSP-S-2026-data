#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,p[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    sort(p+1,p+n+1);
    for(int i=n-1;i>=m;i--)p[i]&=p[i+1];
    cout<<p[m];
    return 0;
}
