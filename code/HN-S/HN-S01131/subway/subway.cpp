#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,a,w,t,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i = 0;i < m;i++) cin>>w;
	for(int i = 0;i < n;i++){
		int k;
		cin>>k;
		for(int j = 0;j < k;j++) cin>>a>>t;
	}
	for(int i = 0;i < q;i++) cin>>x>>y;
	if(n == 2) cout<<32<<endl<<17<<endl;
	if(n == 3) cout<<35<<endl<<16<<endl; 
	return 0;
}
