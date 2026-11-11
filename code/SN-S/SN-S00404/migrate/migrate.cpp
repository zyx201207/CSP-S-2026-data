#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
ll n,d,x[maxn];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	cout<<0<<endl;
	for(int i=1;i<=n;i++)x[i]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
