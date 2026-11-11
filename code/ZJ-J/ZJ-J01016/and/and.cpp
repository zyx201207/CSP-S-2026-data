#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt[50],a[N];
bool vis[N][50];
/*
0011
1111
1100
1100
*/
long long ans;
long long qpow(int x,int y){
	long long res=1;
	while(y){
		if(y&1)
			res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
//		cout<<'!'<<i<<'\n';
		for(int j=0;j<=32&&x;j++){
			vis[i][j]=x%2;
			cnt[j]+=x%2;
			x>>=1;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=6;j>=0;j--)
//			cout<<vis[i][j];
//		cout<<'\n';
//	}
	for(int i=32;i>=0;i--){
//		for(int j=6;j>=0;j--)
//			cout<<cnt[j];
//		cout<<'\n';
		if(cnt[i]>=m){
			ans+=qpow(2,i);
			for(int j=1;j<=n;j++)
				if(!vis[j][i])
					for(int k=0;k<=32;k++){
						cnt[k]-=vis[j][k];
						vis[j][k]=0;
					}
		}
	}
	cout<<ans;
	return 0;
}
