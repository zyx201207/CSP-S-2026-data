#include<bits/stdc++.h>
using namespace std;
const int maxa=2000005;
long long T,n,m,a[maxa],d,To[10][10],ans;
bool flg;
long long read(){
	long long ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
} 
int DFS(int s,int t,int step,int now){
	if(step==To[s][t]&&now!=t) return 0;
	int res=0;
	for(int i=now;i<=t;i++) res+=DFS(s,t,step+1,i);
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	if(c==11||c==12){
		while(T--){
			n=read(),m=read();
			for(int i=1;i<=n;i++) a[i]=read();
			d=a[2]-a[1];
			for(int i=3;i<=n;i++) if(d!=a[n]-a[n-1]) flg=1;
			if(!flg){
				if(d>=m||m/d>=n) printf("0\n");
				else printf("%d\n",n-2*m/d+1);
			}
		}		
	}else if(c==1||c==2){
		while(T--){
			n=read(),m=read();
			for(int i=1;i<=n;i++) a[i]=read();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int now=i,sp=0;
					for(int k=i;k<=j;k++) if(a[i]+m>=a[k]&&a[i]+m<=a[k+1]) now=k,sp++;
					if(now!=j) sp++;
					To[i][j]=sp;
				}
			}
			for(int i=1;i<=n;i++)
			 for(int j=i+1;j<=n;j++) if(DFS(i,j,0,i)==2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
