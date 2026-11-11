#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int n,m,a[320001];
int ans=0ll;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=31;i>=0;i--){
		//2^i=1<<i
		int awa=0;
		for(int j=1;j<=n;j++)
			if(a[j]>=(1ll<<i))awa++;
		if(awa>=m){
			ans|=(1ll<<i);
			for(int j=1;j<=n;j++)
				if(a[j]<(1ll<<i))a[j]=0ll;
				else a[j]&=((1ll<<i)-1ll);
		}
		else{
			for(int j=1;j<=n;j++)
				a[j]&=((1ll<<i)-1ll);
		}
	}
	cout<<ans;
	return 0;
}