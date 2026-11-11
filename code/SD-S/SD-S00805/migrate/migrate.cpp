#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
int c,t,n;
long long d;
long long x[2000001];
int nxt[2000001][21];
int lst[2000001];
int cntlst[2000001];
int dp[5001][5001];
int cnt[5001][5001];
int val[5001][5001];
bool vis[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
//	if(c==0||c==13||c==14){
//		while(t--){//what am i doing what can i do???l.y.k.
////			cerr<<t<<'\n';//four years...
//			cin>>n>>d;//will i afo 735556 no!!!
//			for(int i=1;i<=n;i++){
//				cin>>x[i];
//				cntlst[i]=0;
//			}
//			for(int i=1,j=1;i<=n;i++){
//				while(j+1<=n&&x[j+1]-x[i]<=d)j++;
//				nxt[i][0]=j;
//			}
//			for(int i=n,j=n;i>=1;i--){
//				while(j-1&&x[i]-x[j-1]<=d)j--;
//				lst[i]=j;
//				cntlst[j]++;
//			}
//			long long ans=0;
//			if(x[n]-x[1]<=d*2)for(int i=1;i<=n;i++){
//				ans+=cntlst[nxt[i][0]-1];
//			}
////			cerr<<x[n]-x[1]-d-d<<"???\n";//no. i won't follow yangxiong .
//			cout<<ans<<'\n';
//		}
//		return 0;//eyes are dry. they don't follow my emotion. mo dai wu hua kong zhe zhi
//	}//no winter camp what can i do oh no i think it for 2hrs;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)cnt[i][j]=0,dp[i][j]=0x3f3f3f3f;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
			vis[i]=0;
			dp[i][i]=0;
			cnt[i][i]=0;
//			cntlst[i]=0;
		}
//		for(int i=n,j=n;i>=1;i--){
//			while(j-1&&x[i]-x[j-1]<=d)j--;
//			lst[i]=j;
//			cntlst[j]++;
//		}
		for(int i=1,j=1;i<=n;i++){
			while(j+1<=n&&x[j+1]-x[i]<=d)j++;
			nxt[i][0]=j;
			for(int k=i+1;k<=j;k++){
//				cerr<<i<<'\t'<<k<<'\n';
				dp[i][k]=1;
				cnt[i][k]=1;
			}
			if(j==i+1)vis[i]=1;
		}
		for(int i=n;i>=1;i--){
			for(int k=1;k<21;k++){
				nxt[i][k]=nxt[nxt[i][k-1]][k-1];
			}
		}
		long long ans=0;
		for(int i=n;i;i--){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[nxt[i][0]][j]+1);
			}
		}
			for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
//				int x=dp[i][k];
//				int now=i;
//				while(x){
//					now=nxt[now][__lg(x)];
//					x^=(1<<__lg(x));
//				}
				for(int j=k+1;j<=n;j++){
					if(dp[i][j]==dp[i][k]+dp[k][j]){
//						cerr<<i<<'\t'<<k<<'\t'<<j<<'\n';
						cnt[i][j]=min(cnt[i][j]+cnt[i][k]*cnt[k][j],3);
					}
				}
			} 
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
////				if(dp[i][j]==0x3f3f3f3f)cerr<<"INF\t"; 
////				else 
//				cerr<<cnt[i][j]<<' ';
//			}
//			cerr<<'\n';
//		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cerr<<i<<'\t'<<j<<'\t'<<dp[i][j]<<'\t'<<cnt[i][j]<<'\n';
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
