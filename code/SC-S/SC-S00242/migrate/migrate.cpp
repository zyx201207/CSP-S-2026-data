#include<bits/stdc++.h>
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
#define int long long
using namespace std;
int c,t,n,d,x[2000005];
int f[5005][5005],g[5005][5005],p[5005][3],sum[5005];
inline void read(int &a){
	char ch=getchar();
	bool f=0;
	a=0;
	while('0'>ch||ch>'9'){
		if(ch=='-')f=1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		a=(a<<3)+(a<<1)+ch-'0';
		ch=getchar();
	}if(f)a=-a;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--){
		read(n),read(d);
		for(int i=1;i<=n;++i)read(x[i]);
		if(c==11||c==12){
			if(n<4)puts("0");
			else{
				int gx=x[2]-x[1];
				int L=d/gx;
				if(n<=L||L<=1)puts("0");
				else{
					printf("%lld\n",n-2*L+1);
				}
			}continue;
		}if(c==13||c==14){
			puts("0");
			continue;
		}for(int i=1;i<=n;++i){
			priority_queue<int,vector<int>,greater<int>>ins,del;
			f[i][i]=0;
			ins.push(0);
			int L=i;
			for(int j=i+1;j<=n;++j){
				int p=lower_bound(x+1,x+j+1,x[j]-d)-x;
				while(L<p){
					del.push(f[i][L]);
					while(del.size()&&ins.top()==del.top()){
						ins.pop(),del.pop();
					}++L;
				}if(ins.size())f[i][j]=ins.top()+1;
				else f[i][j]=2e9;
				ins.push(f[i][j]);
			}
		}for(int i=1;i<=n;++i){
			for(int i=0;i<=n;++i)sum[i]=0;
			g[i][i]=1;
			sum[0]=1;
			int L=i;
			for(int j=i+1;j<=n;++j){
				int p=lower_bound(x+1,x+j+1,x[j]-d)-x;
				while(L<p){
					if(f[i][L]<=n)sum[f[i][L]]-=g[i][L];
					++L;
				}if(f[i][j]<=n)g[i][j]=sum[f[i][j]-1];
				else g[i][j]=0;
				if(f[i][j]<=n)sum[f[i][j]]+=g[i][j];
			}
		}int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				ans+=(g[i][j]==2);
			}
		}printf("%lld\n",ans);
	}
}