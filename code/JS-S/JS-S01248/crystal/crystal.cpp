#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005],m,pre[500005];
bool check(ll l,ll r){
    return (a[r]*(r-l+1)-pre[r]+pre[l-1])<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,res=0;
    for(ll r=1;r<=n;r++)
        pre[r]=pre[r-1]+a[r];
    for(ll r=1;r<=n;r++){
        //i want al~ar=x
        while(!check(l,r)&&l<=r)
            l++;
        res=max(res,r-l+1);
    }
    cout<<res;
    return 0;
}
/*5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
