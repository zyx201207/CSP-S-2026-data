#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
void solve(){
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
//	cout<<n<<' '<<d<<'\n';
//	cout<<x[2]-x[1]<<'\n';
	if((x[2]-x[1])*2>d){
		cout<<0<<'\n';
		return;
	}
	long long j=1;
	for(;j*(x[2]-x[1])<=d;j++);
	j--;
	j--;
	if(n-j*2-1<=0){
		cout<<0<<'\n';
		return;
	}
	cout<<n-j*2-1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
//	if(c==)
	while(t--)solve();
	return 0;
}
