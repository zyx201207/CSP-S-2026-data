#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
typedef long long ll;
ll a[MAXN];
ll maxn[MAXN];
bool cmp(int x,int y){
    return x>y; 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		maxn[i]=a[i]&a[i];
	}
	sort(maxn,maxn+n,cmp);
	cout<<maxn[0];
	return 0;
}
