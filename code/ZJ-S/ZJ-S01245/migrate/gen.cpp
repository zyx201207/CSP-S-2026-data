#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,a[N],ans;
mt19937_64 rd(213232334ll);
inline int rnd(int l,int r){
	return rd()%(r-l+1)+l;
}

signed main(){
	freopen("migrate.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout<<"0 1\n";
	n=2e6,d=rnd(1,1e12);
	cout<<n<<' '<<d<<'\n';
	for(int i=1;i<=n;++i) a[i]=rnd(-1e17,1e17);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) cout<<a[i]+i<<' ';
	cout<<'\n';
	return 0;
}

