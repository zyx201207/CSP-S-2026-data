#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
long long a[200005],sum=1073741824-1,maxx,ans;
void dfs(int x,long long summ,int cnt){
	if(cnt>m){
		return ;
	}
	if(x>=n){
		if(cnt==m)	ans=max(ans,summ);
		return ;
	}
	dfs(x+1,summ&a[x],cnt+1);
	dfs(x+1,summ,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=sum&a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==m){
		cout<<sum;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1073741824-1,0);
	cout<<ans;
	return 0;
}
