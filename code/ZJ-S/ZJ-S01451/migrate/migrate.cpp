#include<bits/stdc++.h>
using namespace std;
#define int long long
#define isd(c) (c>=48 && c<=58)

const int MAX=0x3f3f3f3f3f3f3f3f;
const int N=5e3+10;

int dp[N][N];
int c,t;
int n,d;
int a[N];
int dis[N][N];

void solve(int n,int d){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0;
			dis[i][j]=MAX;
		}
	}
	dp[1][1]=1;
	dis[1][1]=0;
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
		dis[i][i]=0;
	}
	int num=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(a[j]-a[k]<=d){
					if(dis[i][k]+1<dis[i][j]){
						dp[i][j]=dp[i][k];
						dis[i][j]=dis[i][k]+1;
					}else if(dis[i][k]+1==dis[i][j]){
						dp[i][j]+=dp[i][k];
					}
				}else{
					break;
				}
			}
		}
	}
	
	
	
//	for(int i=2;i<=n;i++){
//		for(int j=i-1;j>=1;j--){
//			if(a[i]-a[j]<=d){
//				if(dis[j]+1<dis[i]){
//					dp[i]=dp[j];
//					dis[i]=dis[j]+1;
//				}else if(dis[j]+1==dis[i]){
//					dp[i]+=dp[j];
//				}
//			}else{
//				break;
//			}
//		}
//	}

	int s=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[i][j]==2){
				s++;
			}
		}
	}
	cout<<s<<'\n';
}

inline int rd(){
	int f=1,x=0;
	char c;
	for(c=getchar();!isd(c);c=getchar()){
		if(c=='-') f=-1;
	}
	for(;isd(c);c=getchar()){
		x=(x<<3)+(x<<1)+(c-48);
	}
	return x*f;
}
signed main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		solve(n,d);
	}
	
	return 0;
}

