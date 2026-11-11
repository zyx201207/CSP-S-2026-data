#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1073741823;
int n,m,a[N];
bool s;
long long dp[N][N],pd[N][N]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=M;
	}for(int i=1;i<=m;i++){
		dp[0][i]=0;
	}for(int i=1;i<=n;i++){
		s=false;
		for(int j=1;j<=m;j++){
			if(s==false&&(dp[i][j-1]&a[i])>dp[i-1][j]){
				dp[i][j]=(dp[i][j-1]&a[i]);
				s=true;
				pd[i][j]=pd[i][j-1]+1;
			}else if(j>1){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(dp[i-1][j]==dp[i][j-1]){
					if(pd[i-1][j]==m||pd[i][j-1]==m)pd[i][j]=m;
					else pd[i][j]=min(pd[i-1][j],pd[i][j-1]);
				}
				if(max(dp[i-1][j],dp[i][j-1])==dp[i-1][j]){
					pd[i][j]=pd[i-1][j];
				}else{
					pd[i][j]=pd[i][j-1];
				}
			}
			else{
				dp[i][j]=dp[i-1][j];
				pd[i][j]=pd[i-1][j];
			}
		}
	}int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(pd[i][j]==m&&dp[i][j]>maxn)maxn=dp[i][j];
		}
	}cout<<maxn;
	return 0;
}



//#include<bits/stdc++.h>
//using namespace std;
//const int N=2e5+5;
//int n,m,a[N];
//int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}sort(a+1,a+n+1);
//	cout<<a[n-m+1];
//	return 0;
//}

