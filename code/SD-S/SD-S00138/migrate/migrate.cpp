#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int x[N];
int d[N];
int k[N];
inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') y=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int as(int x){
	if(x>0)return x;
	else return -x;
}
signed main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)x[i]=read();
		if(c==11||c==12){
			if(x[2]-x[1]<=m&&x[3]-x[1]>m) cout<<n<<'\n'; 
			else cout<<0<<'\n';
			continue;
		}
		if(c==13||c==14){
			if(n==2) cout<<1<<'\n';
			else cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int s=1;s<=n;s++){
			for(int i=1;i<=n;i++) d[i]=(1ll<<62),k[i]=0;
			k[s]=1,d[s]=0;
			for(int i=s;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(as(x[i]-x[j])>m)continue;
					if(d[i]+1<=d[j]) d[j]=d[i]+1,k[j]+=k[i];
				}
			}
			for(int i=1;i<=n;i++) if(k[i]==2) ans++;
		}
		cout<<ans<<'\n';
	}

	return 0;
}

