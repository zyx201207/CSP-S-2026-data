#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+3;
int n,m,maax,maxx;
int a[N],sum[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],b[a[i]]++,maax=max(maax,a[i]);
    for(int i=1;i<=maax;i++)
        if(b[i]==m){
            cout<<i;
            return 0;
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
