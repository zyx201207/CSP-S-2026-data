#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
long long sss,n,ssss,q,sum;
long long a[5505][5505];
long long w[1000005];
long long b[1000005],c[1000005],d[1000005],e[1000005];
void dfs(long long x,long long st){
	if(st==e[x])d[x]++;
	if(st<e[x]){
		e[x]=st;
		d[x]=1;
	}
	for(int i=1;i<=n;i++){
		if(i==x||c[i]==0||a[x][i]==1e9)continue;
		c[i]=0;
		dfs(i,st+1);
		c[i]=1e9;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>sss>>q;
	if(sss>10){
		for(int i=1;i<=q;i++)cout<<0<<endl;
		return 0;
	}
	while(q--){
		cin>>n>>ssss;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=1e9;
		for(int i=1;i<=n;i++)cin>>w[i];
		for(int i=1;i<=n-1;i++)for(int j=i+1;j<=n;j++)if(w[j]-w[i]<=ssss)a[i][j]=a[j][i]=1;
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){b[j]=c[j]=e[j]=1e9;d[j]=0;}
			b[i]=c[i]=0;
			dfs(i,0);
			for(int j=1;j<=n;j++)if(d[j]==2)sum++;
		}
		cout<<sum/2<<'\n';
	}
	return 0;
} 
