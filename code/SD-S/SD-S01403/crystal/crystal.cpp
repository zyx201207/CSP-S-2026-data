#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int num,m=0;
};
int n,m,ar[500005]={},mod=1e18;
node sum[500005]={};
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1);
	for(int i=2;i<=n;i++){
		sum[i].num=(sum[i-1].num+(ar[i]-ar[i-1])*(i-1))%mod;
		sum[i].m+=(sum[i-1].num+(ar[i]-ar[i-1])*(i-1))/mod;
		if(m<sum[i].num+sum[i].m*mod){
			cout<<i-1;
			break;
		}
	}
	return 0;
}
