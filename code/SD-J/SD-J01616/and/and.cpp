#include <bits/stdc++.h>
using namespace std;
const long long MAXN=2e5+10;
long long n,m,d[MAXN],ans=0,dp[MAXN],maxn=0,sum;
bool vis[MAXN]={false};
/*long long f(long long a){
	long long p=1,cnt;
	while(a){
		if(a&p) cnt++;
		a-=p;
		p<<=1;
	}return cnt;
}
bool cmp(long long a,long long b){
	return f(a)>f(b); 
}*/
void dfs(long long sums){
	if(sums>=m){
		return ;
	}long long z,maxans=0;
	for(int i=1;i<=n;i++){
		long long t;
		if(ans) t=ans&d[i];
		else t=d[i];
		if(!vis[i]&&t>maxans){
			maxans=t;
			z=i;
		}
	}ans=maxans;
	vis[z]=true;
	dfs(sums+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		maxn=max(maxn,d[i]);
	}
	if(m==1){ 
		cout<<maxn;
		return 0;
	}if(m==n){
		sum=d[1];
		for(int i=2;i<=n;i++){
			sum&=d[i];
		}cout<<sum;
		return 0;
	}dfs(0);
	cout<<ans;
	return 0;
}/*
4 2
0000 0000


0011 0011
1111 0011
1100 0000
1100 0000
*/
