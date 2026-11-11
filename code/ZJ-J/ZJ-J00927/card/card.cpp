#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m,a[maxn],b[maxn],c[maxn],ans[maxn];
bool vis[maxn][maxn];
int read(){
	int num=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i;i--){
		if(c[a[i]]==0)c[a[i]]=i;
		b[i]=c[a[i]];
	}
	for(int i=n;i;i--){
		int j=i-1,sum=1;
		while(i>=b[j] && j){
			if(!vis[a[i]][j] && b[i]!=b[j])sum++;
			vis[a[i]][j]=1;
			j--;
		}
		ans[a[i]]+=sum;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}