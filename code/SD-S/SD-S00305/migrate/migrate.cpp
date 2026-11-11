#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();return x*f;
}
const int N=1005;
int c,t,n,d,x[N],res,a,b;
pair<int,int> f[N][N];//first 方法，second路径长度 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c==11||c==12){
		while(t--){
			n=read(),d=read(),a=read();
			if(n==1) cout<<"0\n";
			else{
				b=read();
				for(int i=3;i<=n;++i) read();
				if(a>b) swap(a,b);
				if(a==b||(d/(b-a)*2>=n)) cout<<0<<'\n';
				else{
					int x=(d/(b-a))*2-1;
					if(x<2) cout<<0<<'\n';
					else cout<<n-x<<'\n';
				}
			}
		}
		return 0;
	}
	while(t--){
		n=read(),d=read(),res=0;
		for(int i=1;i<=n;++i) x[i]=read();
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j]={0,1e18};
		for(int i=1;i<n;++i) for(int j=i+1;j<=n;++j)
			if(x[j]-x[i]<=d) f[i][j]=f[j][i]={1,1};
		for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
			if(f[i][k].second+f[k][j].second<f[i][j].second)
				f[i][j]={f[i][k].first*f[k][j].first,f[i][k].second+f[k][j].second};
			else if(f[i][k].second+f[k][j].second==f[i][j].second)
				f[i][j].first+=f[i][k].first*f[k][j].first;
//		for(int chang=3;chang<=n;++chang){
//			for(int i=1, _=n+1-chang ;i<=_;++i){
//				for(int j=1, __=i+chang-1 ,fi1,fi2,se1,se2,fi,se;j<=n;++j){
//					fi=f[i][__].first,se=f[i][__].second,
//					fi1=f[i][j].first,se1=f[i][j].second,
//					fi2=f[j][__].first,se2=f[j][__].second;
//					
//					if(se1+se2<se) f[i][__]={fi1*fi2,se1+se2};
//					else if(se1+se2==se) f[i][__].first+=fi1*fi2;
//				}
//			}
//		}
		for(int i=1;i<n;++i) for(int j=i+1;j<=n;++j) if(f[i][j].first==2)
			++res;
		cout<<res<<'\n';
	}
	return 0;
}//8129 16
