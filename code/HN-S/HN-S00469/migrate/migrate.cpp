#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+20;
int c,t;
LL x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		LL x1=abs((n+1)/d-x[1]);
		LL x2=abs((n+1)/d+x[1]);
		cout<<min(x1,x2)<<endl;
		memset(x,0,sizeof(x));
	}
	
	return 0;
}
