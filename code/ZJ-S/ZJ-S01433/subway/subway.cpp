#include<bits/stdc++.h>
using namespace std;
int w[500000],k[1000],a[501][20000],t[501][20000],chezhan[20000][501];
long long dp[20000];
void gog(int start,int n){
	for(int i=0;i<n;i++){
		if(chezhan[start][i]>0){
			for(int j=0;j<k[i];j++){
				if(dp[a[i][j]-1]==-1){
					dp[a[i][j]-1]=chezhan[start][i]+t[i][j]+dp[start];
					gog(a[i][j]-1,n);
				}else if(dp[a[i][j]-1]>chezhan[start][i]+t[i][j]+dp[start]){
					dp[a[i][j]-1]=chezhan[start][i]+t[i][j]+dp[start];
					gog(a[i][j]-1,n);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	long long te;
	int x[100000],y[100000];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)	cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			chezhan[a[i][j]-1][i]=t[i][j];
		}
	}
	for(int i=0;i<q;i++)	cin>>x[i]>>y[i];
	for(int i=0;i<q;i++){
		for(int j=0;j<m;j++)	dp[j]=-1;
		te=w[x[i]-1]+w[y[i]-1];
		dp[x[i]-1]=0;
		gog(x[i]-1,n);
		te+=dp[y[i]-1];
		cout<<te<<endl;
	}
	return 0;
}
