#include<bits/stdc++.h>
using namespace std;
//int dp[500005];
int c,n,m,d,q,w[500005],a[505][50005],t[505][50005],dp[1005][1005];
int dis[1005][1005];
bool b[1005];
int N=1000000000;
int aaa(int i,int j){
	for(int l=1;l<=m;l++){
		b[i]=1;
		b[j]=1;
		if(b[l]==0){
			if(dis[i][l]==N){
				dis[i][l]=aaa(i,l);
				dis[l][i]=dis[i][l];
			}
			if(dis[l][j]==N){
				dis[l][j]=aaa(i,l);
				dis[j][l]=dis[l][j];
			}
			dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][i]);
		}
		b[j]=0;
		b[i]=0;
	}
	return dis[i][j];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=N;
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			for(int l=1;l<=j;l++){
				dis[a[i][j]][a[i][l]]=min(t[i][j]+t[i][l],dis[a[i][j]][a[i][l]]);
				dis[a[i][l]][a[i][j]]=dis[a[i][j]][a[i][l]];
			}
		}
	}
	int s,f;
	for(int i=1;i<=q;i++){
		cin>>s>>f;
		if(dis[s][f]==N){
			cout<<aaa(s,f)+w[s]+w[f]<<"\n";
		}
		else{
			cout<<dis[s][f]+w[s]+w[f]<<"\n";
		}
	}
}