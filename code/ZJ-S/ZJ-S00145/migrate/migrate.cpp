#include<bits/stdc++.h>
#define int long long
namespace IO{
	using namespace std;
	#define gc getchar
	int readint(){
		int ret=0;bool f=1;char c=gc();
		while(!isdigit(c)){if(c=='-')f=0;c=gc();}
		while(isdigit(c))ret=ret*10+(c&15),c=gc();
		return f?ret:-ret;
	}
}
namespace c1_10{//n<=5000
	using namespace IO;
	const int MAXN=5010;
	int n,T,D,f[MAXN],dis[MAXN],s[MAXN],pos[MAXN];
	void solve(){
		n=readint(),D=readint();
		int ans=0;
		for(int i=1;i<=n;i++)pos[i]=readint();
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof(int)*(n+7));
			memset(s,0,sizeof(int)*(n+7));
			s[i]=f[i]=1,dis[i]=1;int k=i;int l=k;
			for(int j=i+1;j<=n;j++){
				if(pos[j]-pos[j-1]>D)break;
				while(k<j&&pos[j]-pos[k]>D)k++;
				if(l<k)l=k;
				while(l<j-1&&dis[l+1]==dis[k])l++;
				f[j]=s[l]-s[k-1];
				s[j]=s[j-1]+f[j];
				dis[j]=dis[k]+1;
				if(f[j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	void Main(){
		T=readint();
		while(T--)solve();
		return;
	}
}
namespace c11_20{//n<=5000
	using namespace IO;
	const int MAXN=2000010;
	int n,T,D,f[MAXN],dis[MAXN],s[MAXN],pos[MAXN];
	void solve(){
		n=readint(),D=readint();
		int ans=0;
		for(int i=1;i<=n;i++)pos[i]=readint();
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof(int)*(n+7));
			memset(s,0,sizeof(int)*(n+7));
			s[i]=f[i]=1,dis[i]=1;int k=i;int l=k;
			for(int j=i+1;j<=n;j++){
				if(pos[j]-pos[j-1]>D)break;
				while(k<j&&pos[j]-pos[k]>D)k++;
				if(l<k)l=k;
				while(l<j-1&&dis[l+1]==dis[k])l++;
				f[j]=s[l]-s[k-1];
				s[j]=s[j-1]+f[j];
				dis[j]=dis[k]+1;
				if(f[j]==2)ans++;
				if(f[j]>5)break;
			}
		}
		printf("%lld\n",ans);
	}
	void Main(){
		T=readint();
		while(T--)solve();
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=IO::readint();
	if(c<=10)c1_10::Main();
	else c11_20::Main();
	return 0;
}

