#include<bits/stdc++.h>
using namespace std;
int vis[100010],ans[100010];
int a[100010];
void isssort(int n,int m){
	for(int i=1;i<=n;i++){
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,issort=1,nxt=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(nxt>a[i])issort=0;
		nxt=a[i];
	}if(issort){
		isssort(n,m);return 0;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			int& num=a[j];
			if(vis[num]){
				for(int k=1;k<=m;k++){
					if(vis[k]>vis[num])vis[k]=0;
				}
			}else vis[num]=j;
		}for(int j=1;j<=m;j++){
			if(vis[j])ans[j]+=1;
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0; 
}
