#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=5e5+10;
long long w[N];
vector<long long> t[510];
vector<int> a[510];
long long dp[410][410];
int c,n,m,d,q,k[510],xq[N],yq[N],op1;
long long op2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
//	cout<<"*(&*%*"<<"\n";
	for(int i=1;i<=n;i++){
		cin>>k[i];
//		cout<<k[i]<<"\n";
//		cout<<"*(^*&%"<<"\n";
		for(int j=1;j<=k[i];j++){
			cin>>op1>>op2;
			a[i].emplace_back(op1),t[i].emplace_back(op2);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xq[i]>>yq[i];
	}
//	if(c>=7&&c<=11){
//		
//	}
	if(c>=1&&c<=8){
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=1e16;
		for(int i=1;i<=m;i++) dp[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<k[i];j++){
//				cout<<i<<" "<<j<<" "<<a[i][j]<<' '<<t[i][j]<<"\n";
				for(int w=0;w<j;w++){
					//
					dp[a[i][w]][a[i][j]]=min(dp[a[i][w]][a[i][j]],t[i][w]+t[i][j]);
					dp[a[i][j]][a[i][w]]=min(dp[a[i][j]][a[i][w]],t[i][w]+t[i][j]);
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
//		for(int k=1;k<=m;k++){
//			for(int i=1;i<=m;i++){
//				for(int j=1;j<=m;j++){
//					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
//				}
//			}
//		}
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		for(int i=1;i<=q;i++){
			cout<<(w[xq[i]]+dp[xq[i]][yq[i]]+w[yq[i]])<<"\n";
		}
	}
//	else if(c>=12&&c<=19){
//		//希望尽量少转乘
//		//所以只要计算最少转乘多少次就行
//		// 
//	}
	return 0;
}

