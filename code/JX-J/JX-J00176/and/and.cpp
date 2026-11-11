#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=2e5+5;

ll a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;cin>>n>>m;
	m--;
	for(int i=1;i<=n;i++)cin>>a[i];

	sort(a+1,a+1+n);

	ll ans=a[n];
	int i=n-1;

	while(m){
		ans&=a[i];
		i--;
		m--;
	}

	cout<<ans;

	return 0;
}