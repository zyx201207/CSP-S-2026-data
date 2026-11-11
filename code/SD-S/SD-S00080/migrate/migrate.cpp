#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int x[2000005],fl[305][305],cnt[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	if(c<=6){
		while(T--){
			int n=read(),d=read();
			for(int i=1;i<=n;i++) x[i]=read();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					fl[i][j]=1e18;
					cnt[i][j]=0;
				}
				fl[i][i]=0;
				cnt[i][i]=1;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						fl[i][j]=cnt[i][j]=1;
					} 
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(fl[i][k]+fl[k][j]<fl[i][j]){
							fl[i][j]=fl[i][k]+fl[k][j];
							cnt[i][j]=cnt[i][k]*cnt[k][j];
						}
						else if(fl[i][k]+fl[k][j]==fl[i][j]&&i!=k&&i!=j&&j!=k) cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(T--){
		int n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		cout<<0<<'\n';
	}
	return 0;
} 

