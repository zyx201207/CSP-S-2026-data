#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=200000+10;
ll n,m;
ll a[N];
ll sum;
ll tmax=-0x3f3f3f3f;
bool flag[N];
bool cmp(ll a,ll b){
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        flag[i]=false;

    }
    sort(a+1,a+n+1,cmp);
    sum=a[1];
    for(int i=2;i<=m;i++){
        sum&=a[i];
    }
    cout<<sum;
    return 0;
}
