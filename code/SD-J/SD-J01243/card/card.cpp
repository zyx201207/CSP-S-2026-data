#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N],cnt,ans[300010];
ll sum[300010],ft[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	memset(ft,0x3f,sizeof(ft));
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ft[a[i]]=min(ft[a[i]],i);
		sum[a[i]]++;
		if(a[i]>=a[i-1]) cnt++;
	}
		for(ll i=1;i<=m;i++) ans[i]=(sum[i]+1)/2;
		for(ll i=1;i<=m;i++){
			if(sum[i]%2==1) ans[i]+=ft[i]-1;
			cout<<ans[i]<<" ";
		}
		return 0;
	return 0;
} 
