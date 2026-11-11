#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+100,M=2e6+100;
int f[N][N],g[N][N],n,nxt[M],ans;ll d,a[M];
void solve1(){
	int len=1;
	for(int i=n-1;i>=1;i--){
		if(nxt[i]==nxt[i+1])len++;
		else break;
	}
	if(len<=2){
		printf("0\n");
		return;
	}
	len=(len-1)*2;
	len=n-len+1;
	printf("%d\n",max(0,len));
	return;
}
ll qread(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;scanf("%d %d",&c,&_);
	while(_--){
		scanf("%d %lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++)a[i]=qread();
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&a[j+1]-a[i]<=d)j++;
			nxt[i]=j;
		}
		if(c==11||c==12){solve1();continue;}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=0x3f3f3f3f,g[i][j]=0;
			}
		}
		for(int i=1;i<n;i++)f[i][i]=0,g[i][i]=1;
		for(int len=1;len<=n;len++){
			for(int i=1,j=i+len-1;j<=n;i++,j++){
				for(int k=j+1;k<=nxt[j];k++){
					if(f[i][k]<f[i][j]+1)continue;
					if(f[i][k]==f[i][j]+1)g[i][k]+=g[i][j];
					else{
						f[i][k]=f[i][j]+1;
						g[i][k]=g[i][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=g[i][j]==2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}