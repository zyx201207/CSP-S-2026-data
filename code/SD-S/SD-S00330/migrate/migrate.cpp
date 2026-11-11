#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n,d;
int a[N];
int l[N],r[N];
int mx=1e9,o=0;
inline int read(){
	int k=0,k2=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') k2=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*k2;
}
void dfs(int x,int y,int home){
	if(x>y) return;
	if(x==y){
		if(home<mx) mx=home,o=1;
		else if(mx==home) o++;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d) dfs(i,y,home+1);
		else break;
	}
}
void solve(){
	n=read(),d=read();
	int ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	if(n>=20){
		cout<<0<<"\n";
		return; 
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
		mx=1e9,o=0;
		dfs(i,j,0);
		if(o==2) ans++;
	}
	cout<<ans<<"\n"; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	c=read(),t=read();
	while(t--) solve();
	return 0;
}

