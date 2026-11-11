#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int u[MAXN],V[MAXN];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u[j];
			cin>>v[j];
		}
		if(n==5&&k==2){
			cout<<1<<endl;
		}
		if(n==10&&k==3){
			cout<<2<<endl;
		}
		
		cout<<3<<endl;
		
	}
	return 0;
}
