#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010];
int bit[40][200010];
int ban[200010];
long long ans=0;
signed main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		for(j=35;j>=0;j--){
			long long t=(1ll<<j);
			if(a[i]&t)bit[j][i]=1;
		}
	}
	for(i=35;i>=0;i--){
		int sum=0;
		for(j=1;j<=n;j++){
			if(ban[j])continue;
			if(bit[i][j])sum++;
		}
		if(sum<m)continue;
		ans|=(1ll<<i);
		for(j=1;j<=n;j++){
			if(ban[j])continue;
			if(bit[i][j]==0)ban[j]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

