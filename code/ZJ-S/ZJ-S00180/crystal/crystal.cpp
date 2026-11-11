#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=500005;
ll a[MAXN],pre[MAXN];
ll  n,m;
bool check(int id,ll mid){
    return ((long long)a[id]*mid-(pre[id]-pre[id-mid])<=m);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll l=0,r=i,can;
        while(l<=r){
            ll mid=(l+r)/2;
            if(check(i,mid)){
                l=mid+1;
                can=mid;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,can);
    }
    cout<<ans;
	return 0;
}
//7 10
//-5 -4 -3 -1 1 2 3
//10 7
//-54 -23 -4 -2 -2 -1 5 7 9 12