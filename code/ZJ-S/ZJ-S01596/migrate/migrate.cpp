#include<bits/stdc++.h>
#include<ctime>
#define int long long
#define PII pair<int,int>
#define mk(a,b) make_pair(a,b)
using namespace std;
const int N=2e6+10,inf=1e12;
int n,d;
int a[N];
int L[N],R[N];
void solve(){

	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;++i){
			cin>>a[i];
			L[i]=R[i]=1;
	}

	int l,r;
	for(l=1,r=1;l<=n;++l){
		while(r<=n&&a[r+1]-a[l]<=d) ++r;
		if(r<=n) L[r]+=L[l];
		if(r>=n) break;
	}
	for(r=n,l=n;r>=1;--r){
		while(l>=1&&a[r]-a[l-1]<=d) --l;
		if(l>=1) R[l]++;
		if(l<=1) break;
	}
	for(int i=1;i<n;++i){
		ans+=(L[i+1]-1)*(R[i]-1);
	}

	cout<<ans<<"\n";

	return;
}
void sA(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)
		cin>>a[i];

	if(n<=3){
		cout<<0<<"\n";
		return;
	}
	int len=d/(a[2]-a[1]);
	if(len<=1||len*2>n){
		cout<<0<<"\n";
		return;
	}

	cout<<n-len*2+1<<"\n";
	return;
}
void sB(){

	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		L[i]=R[i]=0;
	}

	int ans=0;
	a[n+1]=a[n]+d;
	a[0]=a[1]-d;

	if(n<=3){
		cout<<0<<"\n";
		return;
	}

	int l,r;

	for(l=1,r=1;l<=n;++l){
		while(r<=n&&a[r+1]-a[l]<=d) ++r;
		if(r<=n) L[r]++;
		if(r>=n) break;
	}

	for(r=n,l=n;r>=1;--r){
		while(l>=1&&a[r]-a[l-1]<=d) --l;
		if(l>=1) R[l]++;
		if(l<=1) break;
	}

	for(int i=1;i<n;++i)
		ans+=R[i]*L[i+1];

	cout<<ans<<"\n";

	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,T=1;
	cin>>c>>T;

	while(T--){
		if(c==11||c==12) sA();
		else if(c==13||c==14) sB();
		else solve();
	}

	// cerr<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}