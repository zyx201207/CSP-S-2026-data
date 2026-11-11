#include<bits/stdc++.h>//48pts
using namespace std;
int n,m,a[500005],ans[300005],stk[500005],top,id[300005];bool vis[300005],visans[300005];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		memset(visans,0,sizeof visans);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]])stk[++top]=a[j],id[a[j]]=top,vis[a[j]]=1;
			else {
				while(top>id[a[j]])vis[stk[top--]]=0;
			}
		}
		while(top){
			if(!visans[stk[top]])ans[stk[top]]++,visans[stk[top]]=1;
//			cout<<stk[top]<<" ";
			vis[stk[top--]]=0;
		}
//		cout<<"\n";
	} 
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*_________________              ________
/                                    |
|                                    |
|									 |
|              _____                 |
|                  |                 | 
|                  |                 |
\_________________/               ___|___   v e   me more points;thank you CCF
wo yao shang mi huo xing wei da shang luoguid:1219162*/ 
