#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e6+5;

namespace IO{
	#define gc getchar_unlocked()

	template<typename T>
	void read(T &x){
		char c;
		int sgn=1;
		while(c=gc,c<'0'||c>'9')if(c=='-')sgn=-1;
		x=c-'0';
		while(c=gc,c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0';
		x*=sgn;
	}

	template<typename T>
	void print(T x){
		if(x<0)putchar('-'),x=-x;
		if(x/10)print(x/10);
		putchar(x%10+'0');
	}

	#undef gc
}
using IO::read;
using IO::print;

int n;
ll d,x[N];
ll l[N],r[N];
int dis[505][505],g[505][505];

void Solve(){
	memset(dis,0,sizeof(dis));
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++){
		int p=i+1;
		while(p<=n&&x[p]-x[i]<=d)dis[i][p]=1,g[i][p]=1,p++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(dis[i][k]&&dis[k][j]){
					if(!dis[i][j]||(dis[i][j]>dis[i][k]+dis[k][j])){
						dis[i][j]=dis[i][k]+dis[k][j];
						g[i][j]=g[i][k]*g[k][j];
					}else if(dis[i][j]==dis[i][k]+dis[k][j]){
						g[i][j]+=g[i][k]*g[k][j];
					}
				}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(g[i][j]==2)ans++;
	}
	cout<<ans<<'\n';
}

void Solve2(){
	int p=n;
	r[n]=0;
	for(int i=n-1;i>=1;i--){
		while(x[p]-x[i]>d&&p>i)p--;
		if(p!=i)r[i]=p;
	}
	p=1;
	l[1]=0;
	for(int i=2;i<=n;i++){
		while(x[i]-x[p]>d&&p<i)p++;
		if(p!=i)l[i]=p;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(r[i]&&r[i]-i>=2){
			if(r[r[i]]&&r[r[i]-1]&&r[r[i]]==r[r[i]-1]&&(!r[r[i]-2]||r[r[i-2]]!=r[i])){
				int x=1,y=1;
				int t1=i,t2=r[r[i]];
				while(t1){
					if(l[t1]&&r[t1-1]==r[t1])break;
					x++;
					t1=l[t1];
				}
				while(t2){
					if(r[t2]&&l[t2+1]==l[t2])break;
					y++;
					t2=r[t2];
				}
				ans+=1ll*x*y;
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(n<=300)Solve();
		// Solve2();
	}
	return 0;
}