#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num,s[40]={0};
}a[200010];
long long n,m,vis[40],dp[2005][2005],ans=-1,mx=0,cnt=1,nw=1,vs[200010];
bool cmp(node x,node y){
	return (x.s[cnt])>(y.s[cnt]);
}
bool cmp2(node x,node y){
	return x.num>y.num;
}
void dfs(long long l,long long cnt){
	if(l>m){
		ans=max(ans,cnt);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(!vs[i]){
			vs[i]=1;
			dfs(l+1,(cnt==-1?a[i].num:cnt&a[i].num));
			vs[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num;
		long long res=a[i].num,tt=-1;
		while(res){
			vis[++tt]+=(res&1);
			a[i].s[tt]=(res&1);
			res>>=1;
		}
		mx=max(mx,tt);
	}
	if(n<=20){
		dfs(1,-1);
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		sort(a+1,a+n+1,cmp2);
		for(long long i=1;i<=n;i++){
			dp[i][i]=a[i].num;
		}
		for(long long l=1;l<=m;l++){
			for(long long i=1;i+l-1<=n;i++){
				long long j=i+l-1;
				for(long long k=1;k<j;k++){
					dp[i][j]=max(dp[i][k]&dp[k+1][j],dp[i][j]);
				}
				if(l==m) ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans;
		return 0;
	}
	for(long long i=mx;i>=0;i--){
		if(vis[i]>=m){
			cnt=i;
			sort(a+nw,a+n+1,cmp);
			nw=max(nw,vis[i]+1);
		}
	}
	for(long long i=1;i<=m;i++){
		if(ans==-1) ans=a[i].num;
		else ans&=a[i].num;
	}
	cout<<ans;
	return 0;
}