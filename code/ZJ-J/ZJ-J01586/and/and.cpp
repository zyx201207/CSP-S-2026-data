#include<bits/stdc++.h>
using namespace std;
long long sum,b[200010],a[200010][50],n,m,maxs,c[200010];
void totwo(int x,int i){
	long long cnt=0;
	while(x>0){
		a[i][++cnt]=x%2;
		x/=2;
	}
	maxs=max(maxs,cnt);
	return ;
}
void dfs(int x,int cnt){
	int ct=0;
	if(x==0) return ;
	for(int i=1;i<=cnt;i++) if(a[b[i]][x]==1) ct++;
	if(ct>=m){
		int k=0;
		for(int i=1;i<=cnt;i++) if(a[b[i]][x]==1) c[++k]=b[i];
		cnt=k;
		for(int i=1;i<=cnt;i++) b[i]=c[i];
		sum+=pow(2,x-1);
	}
	dfs(x-1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int x,i=1;i<=n;i++){
		cin>>x;
		totwo(x,i);
	}
	for(int i=1;i<=n;i++) b[i]=i;
	dfs(maxs,n);cout<<sum;
	return 0;
}
