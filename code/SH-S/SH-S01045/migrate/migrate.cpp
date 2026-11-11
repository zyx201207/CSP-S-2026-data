#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10,M=2*N,inf=0x3f3f3f3f;
int n,C,T;
ll d;
ll pos[N];
int f[5005][5005],b[5005][5005];
void solve(){
	int ans=0;
	memset(f,0x3f,sizeof(f));
	memset(b,0,sizeof(b));
	for(int u=1;u<=n;u++){
		int j=u;//
		b[u][u]=1;
		f[u][u]=0;
		for(int i=u+1;i<=n;i++){
			while(j+1<=i&&pos[i]-pos[j]>d)	j++;
			if(j==i)	break;
			f[u][i]=f[u][j]+1;
			for(int k=j;k<=i;k++){
				if(f[u][i]==f[u][k]+1){
					b[u][i]+=b[u][k];
				}
				if(b[u][i]>2){
					break;
				}
			}
		}
		for(int i=u+1;i<=n;i++){
			if(b[u][i]==2){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&C,&T);
	if(C>10){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&pos[i]);
		}
		puts("0");
	} 
	while(T--){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&pos[i]);
		}
		solve();
	}
	return 0;
} 
