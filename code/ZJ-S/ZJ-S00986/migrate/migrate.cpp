#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
int c,t,goal,ANS,ans;
int n,d,a[maxn];
bool flg;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void dfs(int now,int used,int length,int lim){
	if(length==lim&&now==goal){ANS++; return ;}
	if(ANS>2) return ;
	if(length>lim) return ;
	for(int i=now+1;;i++){
		if(a[i]-a[now]<=used) dfs(i,used-(a[i]-a[now]),length+1,lim);
		else return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read();d=read();memset(a,0,sizeof a);
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				flg=0;
				int shortest=1;
				int k=i;
				int now=a[i];
				for(;k<=j;k++){
					if(a[j]>a[j-1]+d){flg=1;break;}
					if(a[k]-now<=d) continue;
					k--,shortest++,now=a[k];
				}
				if(flg) continue;
				ANS=0;
				goal=j;
				dfs(i,d,1,shortest);
				if(ANS==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}