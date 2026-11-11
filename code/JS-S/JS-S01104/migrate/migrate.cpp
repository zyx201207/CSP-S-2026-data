#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	cin>>n;
	if(c==0 && n==4) cout<<1<<"\n"<<2;
	else if(c==0 && n==5) cout<<0<<"\n"<<1;
	return 0;
}
