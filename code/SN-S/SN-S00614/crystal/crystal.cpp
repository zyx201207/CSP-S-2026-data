#include<iostream>
#include<algorithm>
#define  int  __int128
using namespace std;
constexpr int N=5e5+5;
bool Beg;
int n,m,a[N],b[N];
int c[N],s[N];
bool check(int x){
	x--;
	for(int i=2;i+x<=n;i++){
		int d=c[i]-c[i+x]-s[i+x]*x;
		if(d<=m)return 1;
	}
	return 0;
}
bool End;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long nn,mm; cin>>nn>>mm;
	n=nn,m=mm;
	for(int i=1;i<=n;i++){
		long long x; 
		cin>>x,a[i]=x;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		b[i]=a[i]-a[i-1];
	for(int i=n;i>1;i--)
		s[i]=s[i+1]+b[i],
		c[i]=c[i+1]+s[i];
	int L=1,R=n;
	while(L+1<R){
		int mid=(L+R)>>1; 
		if(check(mid))L=mid;
		else R=mid;
	}
	long long Out=L;
	cout<<Out<<'\n';
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
