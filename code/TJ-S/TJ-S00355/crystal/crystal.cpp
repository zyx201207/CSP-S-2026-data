#include<bits/stdc++.h>
using namespace std;
namespace T1{
	const int N=5e5+10,LOG=20;
	const long long INF=0x3f3f3f3f3f3f3f3f;
	int n;
	long long m,a[N],st[LOG][N],s[N];
	bool check(int x){
		bool res=0;
		int j=__lg(x);
		for(int i=x;i<=n;i++){
			long long mx=max(st[j][i-x+1],st[j][i-(1<<j)+1]);
			res|=(mx*x-(s[i]-s[i-x])<=m);
		}
		return res;
	}
	void solve(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin >> n >> m;
		for(int i=1;i<=n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		memcpy(st[0],a,sizeof(st[0]));
		for(int j=1;j<LOG;j++){
			for(int i=1;(i+(1<<j)-1)<=n;i++){
				st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
		int L=0,R=n;
		while(L<R){
			int mid=(L+R+1)>>1;
			if(check(mid)) L=mid;
			else R=mid-1;
		}
		cout << L << '\n';
	}
}
//namespace force{
//	const int N=5e5+10;
//	const long long INF=0x3f3f3f3f3f3f3f3f;
//	int n;
//	long long m,a[N],s[N];
//	bool check(int x){
//		bool res=0;
//		for(int i=x;i<=n;i++){
//			long long mx=-INF;
//			for(int j=i-x+1;j<=i;j++) mx=max(mx,a[j]);
//			res|=((mx*x-(s[i]-s[i-x]))<=m);
//		}
//		return res;
//	}
//	void solve(){
//		freopen("crystal.in","r",stdin);
////		freopen("crystal.out","w",stdout);
//		cin >> n >> m;
//		for(int i=1;i<=n;i++) cin >> a[i];
//		sort(a+1,a+n+1);
//		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//		int L=0,R=n;
//		while(L<R){
//			int mid=(L+R+1)>>1;
//			if(check(mid)) L=mid;
//			else R=mid-1;
//		}
//		cout << L << '\n';
//	}
//}
//namespace RAND{
//	mt19937 rng(time(NULL));
//	long long rd(long long l,long long r){return rng()%(r-l+1)+l;}
//	void solve(){
//		freopen("crystal.in","w",stdout);
//		const long long N=8,M=1e12;
//		int n=rd(1,N),m=rd(1,M);
//		cout << n << ' ' << m << '\n';
//		for(int i=1;i<=n;i++) cout << rd(1,m) << ' ';
//		cout << '\n'; 
//	}
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	T1::solve();
	
	
	return 0;
}
