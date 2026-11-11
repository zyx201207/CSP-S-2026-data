#include<bits/stdc++.h>
#define INF 1e18
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=gc;
	}
	return x*f;
}
const int N=2000009;
int c,T;
int n,d;
int f[N];
int a[N];
int lst[N];
int nxt[N]; 
void solve_smn(){
	rep(i,1,n) a[i]=read();
	a[n+1]=2*INF;
	rep(i,1,n){
		lst[i]=lower_bound(a,a+n+1,a[i]-d)-a;
	}
	rep(i,1,n){
		nxt[i]=upper_bound(a,a+n+1,a[i]+d)-a;
		nxt[i]--;
	}
	int sum=0;
	rep(st,1,n){
		int i;
		f[st]=1;
		for(i=st;i<=n;i=nxt[i]){
			if(i==nxt[i]) break;
			rep(j,i+1,nxt[i]){
				if(lst[j]==i||a[j]-a[st]<=d) f[j]=f[i];
				else if(lst[j]==(i-1)) f[j]=1+f[i-1];
				else f[j]=3;
			}
		//	cout<<"/bx    "<<i<<endl;
		}
		rep(j,st,i){
			sum+=(f[j]==2);
		}
	}
	cout<<sum<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		solve_smn();
//		else if(c<=12) solveA();
//		else solveB();
	}
			
	return 0;
}

