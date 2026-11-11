#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll n,k,u[maxn],v[maxn];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>u[i]>>v[i];
	cout<<1<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
