#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	int a[n][d];
	int t[n][d];
	int r[q][2];
	int k[n];
	int sum=n+m;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>r[i][0]>>r[i][1];
	}
	int G[sum][sum];
	for(int i=0;i<sum;i++){
		for(int j=0;j<=sum;j++){
			G[i][j]=INT_MAX;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			G[i][a[i][j]+n]=t[i][j];
			G[a[i][j]+n][i]=t[i][j];
		}
	}
	for(int i=0;i<q;i++){
//		迪杰斯特拉，不会写，来年再战吧。 
	}
	return 0;
}
