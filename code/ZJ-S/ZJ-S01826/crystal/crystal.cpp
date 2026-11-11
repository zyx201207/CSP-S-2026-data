#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,mx=0;
	ll sum=0;
	for(int r=1;r<=n;r++){
		while(m<(r-l)*a[r]-sum) sum-=a[l],l++;
		mx=max(mx,r-l+1);
		sum+=a[r];
	}
	cout<<mx<<'\n';
	return 0;
}
