#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[50]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,
524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int dfs(int x){
	int sum=0;
	while(x>0){
		x-=b[upper_bound(b+1,b+31,x)-b-1];
		sum++;
	}
	return sum;
}
struct node{
	int yi,ai,du;
}c[N];
struct node2{
	int ch,da;
}dp[N][2];
bool cmp(node a,node b){
	if(a.du!=b.du) return a.du>b.du;
	else if(a.yi!=b.yi) return a.yi>b.yi;
	else return a.ai>b.ai;
}
signed main(){
	ioi;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i].du=lower_bound(b+1,b+31,a[i])-b-1;
		c[i].yi=dfs(a[i]);
		c[i].ai=a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		sort(a+1,a+1+n);
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		int ans=0,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(sum==0) sum=a[j];
					else sum=(sum&a[j]);
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	sort(c+1,c+1+n,cmp);
	dp[1][1].da=c[1].ai;
	dp[1][1].ch=1;
	for(int i=2;i<=n;i++){
		if(dp[i-1][1].da>dp[i-1][0].da){
			dp[i][0].da=dp[i-1][1].da;
			dp[i][0].ch=dp[i-1][1].ch;
		}
		else{
			dp[i][0].da=dp[i-1][0].da;
			dp[i][0].ch=dp[i-1][0].ch;
		}
		if((dp[i-1][0].da&c[i].ai)>(dp[i-1][1].da&c[i].ai)){
			dp[i][1].da=(dp[i-1][0].da&c[i].ai);
			dp[i][1].ch=dp[i-1][0].ch+1;
		}
		else{
			dp[i][1].da=(dp[i-1][1].da&c[i].ai);
			dp[i][1].ch=dp[i-1][1].ch+1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dp[i][1].ch==m)ans=max(ans,dp[i][1].da);
		if(dp[i][0].ch==m)ans=max(ans,dp[i][0].da);
	}
	cout<<ans;
	return 0;
}
