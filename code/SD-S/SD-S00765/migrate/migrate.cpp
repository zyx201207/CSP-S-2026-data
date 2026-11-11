#include <iostream>
#define int long long
using namespace std;
const int N=2e6+10;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
int T;
int n,d;
int x[N];
void planA(){
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		int dx=x[n]-x[n-1],q=0;
		if(dx<0) dx=-dx;
		while(q*dx<=d) q++;
		if(q==2 || q==1 || q>=n){cout<<"0\n";continue;}
		cout<<n-(q+q-2)+1<<'\n';
	}
	return ;
}
int num,res;
void dfs(int id,int l,int u,int v){
	if(id==v){
		if(res==l){
			num++;
			if(num>2) res--,num=0;
		}else if(res>l) res=l,num=1;
		return ; 
	}
	if(l>=res) return ;
	for(int i=id+1;i<=n;i++){
		if(x[i]-x[id]>d) break;
		dfs(i,l+1,u,v);
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read();
	T=read();
	if(c>=11&&c<=12){
		planA();
		return 0;
	}
	while(T--){
		int ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				num=0,res=0x3f3f3f3f3f3f;
				dfs(u,0,u,v);
				if(num==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
