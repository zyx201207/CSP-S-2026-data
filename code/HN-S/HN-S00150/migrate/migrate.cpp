#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
const int N=2e6+10;
ll x[N];
void solve(){
	int n=read();ll d=read();
	rep(i,1,n) x[i]=read();
	ll ans=0;
	rep(i,1,n-3){
		rep(j,i+3,n){
			if(x[j]-x[i]<=d) continue;
			if(x[j]-x[i]>=2*d) break;
			int y=x[j]-x[i]-d+1;
			if(j-i-1>y) continue;
//			cout<<i<<" "<<j<<" "<<y<<"\n";
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		solve();
	}
	return 0;
} 
/*
0 1
5 4
1 4 5 6 7
*/ 
