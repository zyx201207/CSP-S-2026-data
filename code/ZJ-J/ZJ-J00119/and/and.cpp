#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll a[N],n,m;
bool cmp(ll x,ll y){
	if(x!=y) return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
}


