#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,a[N],b[N][35],v[N];
void dfs(int x,int k){
	if(x==m+1){
		int c[35],s=0;
		for(int j=1;j<=30;j++){
			int f=1;
			for(int i=1;i<=m;i++)if(b[v[i]][j]==0){f=0;break;};
			c[j]=f;
		}
		for(int i=30;i>0;i--)if(c[i])s+=pow(2,i-1);
		ans=max(ans,s);
		return ;
	}
	for(int i=k;i<=n;i++){
		v[x]=i;
		dfs(x+1,i+1);
		v[x]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i],j=0;
		while(t>0){
			b[i][++j]=t%2;
			t/=2;
		}
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}