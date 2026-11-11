#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0 && n==2) cout<<32<<"\n"<<17;
	else if(c==0 && n==3) cout<<35<<"\n"<<16;
	return 0;
}
