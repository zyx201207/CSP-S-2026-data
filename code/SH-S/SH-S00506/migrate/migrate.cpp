#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');write(-1*x);return;
	}
	if(x>=10){
		write(x/10);
	}
	putchar('0'+x%10);
	return;
}
const long long N=2000105;
long long c,t,n,d,x[N],pre[N],ne[N],pred[N],ned[N],precnt[N],necnt[N],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();ans=0;
		for(int i=1;i<=n;i++){
			x[i]=read();pre[i]=ne[i]=pred[i]=ned[i]=precnt[i]=necnt[i]=0;
		}
		for(int i=1,j=1;i<=n;i++){
			while(j+1<=n&&x[j+1]-x[i]<=d){
				j++;
			}
			ne[i]=j;
			if(i!=j){
				necnt[j]++;
			}
		}
		for(int i=n,j=n;i>=1;i--){
			while(j-1>=1&&x[i]-x[j-1]<=d){
				j--;
			}
			pre[i]=j;
			if(i!=j){
				precnt[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(ne[pre[i]]==i){
				pred[i]=pred[pre[i]]+necnt[i];
			}
			else{
				pred[i]=1+necnt[i];
			}
		}
		for(int i=n;i>=1;i--){
			if(pre[ne[i]]==i){
				ned[i]=ned[ne[i]]+precnt[i];
			}
			else{
				ned[i]=1+precnt[i];
			}
		}
		for(int i=1;i<n;i++){
			//u!=x v!=y
			long long x=pre[i],y=ne[i+1];
			if(ne[x]==i+1&&pre[y]==i&&i!=x&&i+1!=y){
				ans+=(pred[x]-1)*(ned[y]-1);
			}
			//u==x v!=y
			if(pre[y]==i&&i+1!=y){
				ans+=necnt[i+1]*(ned[y]-1);
			}
			//u!=x v==y
			if(ne[x]==i+1&&i!=x){
				ans+=(pred[x]-1)*precnt[i];
			}
			//u==x v==y
			if(pre[i+1]!=i&&ne[i]!=i+1){
				ans+=necnt[i+1]*precnt[i];
			}
		}
		write(ans);putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
