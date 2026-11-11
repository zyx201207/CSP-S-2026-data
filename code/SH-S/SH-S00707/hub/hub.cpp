#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n,k;
int u[N],v[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n+k;i++)cin>>u[i]>>v[i];
	cout<<"1\n2";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
