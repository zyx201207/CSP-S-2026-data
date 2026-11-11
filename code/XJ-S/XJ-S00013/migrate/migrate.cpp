#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d;
int x[N];
signed main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d) x[i]=1e18+1;
		}
		
	}
	return 0;
	//fclose(stdin);
	//fclose(stdout);
}
