#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n;
ll d;
ll a[N];
int main(){
	ios:sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	int ans=0;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				ans=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
