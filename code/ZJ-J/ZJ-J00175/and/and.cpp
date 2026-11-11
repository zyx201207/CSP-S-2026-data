#include<bits/stdc++.h>
using namespace std;
int a[300005],Cnt,maxn,sum,n,m,vis[300005];
int dfs(int num,int sum,int deep){
	if(deep>m)return sum;
	if(vis[num])return 0;
	vis[num]=1;
	cout<<num<<' ';
	int s=0;
	for(int i=1;i<=n;i++)s=max(s,dfs(i,sum&a[i],deep+1));
	vis[num]=0;
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	sum=a[1];
	maxn=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		sum&=a[i];
	}
	if(m==1)cout<<maxn;
	else if(m==n)cout<<sum;
	else if(m==n-1){
		int sum1=a[1],sum2=a[2];
		for(int i=2;i<n;i++)sum1&=a[i];
		for(int j=3;j<=n;j++)sum2&=a[j];
		cout<<max(sum1,sum2);
	}
	else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
	}
	else if(m==3){
		int maxn=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)maxn=max(maxn,a[i]&a[j]&a[k]);
		cout<<maxn;
	}
	else if(m==4){
		int maxn=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int y=k+1;y<=n;y++)maxn=max(maxn,a[i]&a[j]&a[k]&a[y]);
		cout<<maxn;
	}
	else if(m==5){
		int maxn=0;
		for(int i=1;i<=n;i++)for(int j=j+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int y=k+1;y<=n;y++)for(int x=k+1;x<=n;x++)maxn=max(maxn,a[i]&a[j]&a[k]&a[y]&a[x]);
		cout<<maxn;
	}
}