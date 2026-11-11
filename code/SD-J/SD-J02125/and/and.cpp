#include<iostream>
using namespace std;
long long n,m,a[200005],ans,cnt,sum;
void dfs(long long x){
	if(cnt==m){
		ans=max(ans,sum);
		cnt=0;
		sum=0;
		return ; 
	}
	for(long long i=x;i<=n;i++){
		sum=a[i]&a[x];
		cnt++;
		dfs(i+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
