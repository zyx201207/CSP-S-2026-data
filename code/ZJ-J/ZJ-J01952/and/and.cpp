#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[200005],ans=0;
void dfs(long long now,long long tmp,long long sum){
	if(tmp==m){
		ans=max(sum,ans);
		return;
	}
	if(now>n) return;
	long long s=sum;
	if(sum==0){
		sum=a[now];
	}else{
		sum&=a[now];
	}
	dfs(now+1,tmp+1,sum);
	sum=s;
	dfs(now+1,tmp,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1LL,0LL,0LL);
	cout<<ans<<'\n';
	return 0;
}
