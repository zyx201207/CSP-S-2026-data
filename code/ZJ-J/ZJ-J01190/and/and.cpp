#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-48,ch=getchar();
	return ret*f;
}
const int maxn=2e5+5,lg=32;
int n,m,a[maxn],cnt,ans;
int s[maxn][lg];
int vis[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		int x=a[i];
		for(int j=0;j<=30;j++)s[i][j+1]=(x>>j)&1;
	}
	for(int j=lg;j>=1;j--){
		cnt=0;
		for(int i=1;i<=n;i++)if(s[i][j]&&vis[i]==0)cnt++;
		if(cnt>=m){
			for(int i=1;i<=n;i++)if(!s[i][j])vis[i]=1;
			ans|=1<<(j-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}