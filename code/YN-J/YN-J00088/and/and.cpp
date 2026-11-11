#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200500],sum,num[200500];
void dfs(long long now,long long nowi){
	if(now==m){
		long long s=num[0];
		for(long long i=1;i<m;i++)s&=num[i];
		sum=max(sum,s);
		return;
	}
	for(long long i=nowi;i<n;i++){
		num[now]=a[i];
		dfs(now+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	dfs(0,0);
	cout<<sum;
}
