#include<bits/stdc++.h>
#define ll long long
using namespace std;
int Tid,T,n,m,K,x,y;
void solve()
{
	cin>>n>>K;
	for(int i=1;i<n;i++){
		cin>>x>>y;
	}
	m=n/2;
	int k=ceil(1.0*m/(K+1));
	cout<<(k+1)/2+1<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Tid>>T;
	while(T--)solve();
	return 0;
}
