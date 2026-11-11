#include<bits/stdc++.h>
using namespace std;
int ans,a[200005],n,m,f[200005][1005];
inline void dfs(int k,int u,int sum){
	if(sum<ans)return;
	if(k==m){
		ans=max(sum,ans);
		return;
	}
	for(int i=u+1;i<=n;i++)dfs(k+1,i,sum&a[i]);
}
void work1(){for(int i=1;i<=n-m+1;i++)dfs(1,i,a[i]);}
void work2(){for(int i=1;i<=n;i++)ans=max(ans,a[i]);}
void work3(){ans=a[1];for(int i=2;i<=n;i++)ans&=a[i];}
void work4(){
	for(int i=1;i<=n;i++){
		f[i][1]=max(a[i],f[i-1][1]);
		for(int j=2;j<=min(i,m);j++)
			f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
	}
	ans=f[n][m];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20||m==2||m==n-1)work1();
	else if(m==1)work2();
	else if(m==n)work3();
	else work4();
	cout<<ans;
	return 0;
}
