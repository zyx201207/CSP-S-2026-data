#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
const int M=305;
int c,t,n,d,a[N];
int sum[M][M];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while('0'<=ch && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void solve(){
	while(t--){
		n=read(); d=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int gc=a[2]-a[1];
		d=d-(d%gc);
		if (d<=gc){
			cout<<"0\n";
			continue;
		} 
		if ((d+d-gc)/gc>n) cout<<"0\n";
		else cout<<n-(d+d-gc)/gc<<"\n";
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if (c==11 || c==12){
		solve();
		return 0;
	}
	while(t--){
		n=read(),d=read();
		for (int i=1;i<=n;i++) a[i]=read();
		memset(sum,0,sizeof(sum));
		for (int i=1;i<=n;i++){
			for (int j=i+2;j<=n;j++){
				if (a[j]-a[i]<=d) {
					sum[i][j]++;
					continue;
				}
				for (int k=i+1;k<j;k++){
					if (a[k]-a[i]<=d && a[j]-a[k]<=d){
						sum[i][j]++;
					}
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+2;j<=n;j++){
				if (sum[i][j]==2) ans++;
				for (int k=i+1;k<j;k++){
					if (sum[i][k]==2 && sum[k][j]==1) ans++;
					else if (sum[i][k]==1 && sum[k][j]==2) ans++;
					
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
