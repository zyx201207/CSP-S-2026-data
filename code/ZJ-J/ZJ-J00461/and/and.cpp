#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],mx=-1,dfsmx=-1,dp[200001][5],zero=0;
bool vis[200001];
void dfs(int pos,int zhi){
	if(pos==m+1){
		dfsmx=max(dfsmx,zhi);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		dfs(pos+1,zhi&a[i]);
		vis[i]=false;
	}
	return;
}
inline int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
bool cmp(const int a,const int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==0){
			zero++;
		}
		mx=max(mx,a[i]);
	}
	if(n-zero<m){
		cout<<'0';
		return 0;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==2){
		mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);	
			}
		}
		cout<<mx;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(n<=21){
		for(int i=1;i<=n;i++){
			vis[i]=true;
			dfs(2,a[i]);
			vis[i]=false;
		}
		cout<<dfsmx;
		return 0;
	}else{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}
	return 0;
}
