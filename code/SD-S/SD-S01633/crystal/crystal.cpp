#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500005];
ll sum[500005];
ll ans;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)    sum[i]=sum[i-1]+a[i];
	for(ans=2;ans*a[ans]-sum[ans]<=m&&ans<=n;ans++){}
	cout<<--ans;
	return 0;
}
