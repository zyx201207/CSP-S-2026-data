#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e6+5,M=5e5+5;
int c,t,a[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		if(c==11||c==12){
			int g=a[2]-a[1];
			if(d<g||d>a[n]-a[1]) cout<<0<<"\n";
			else {
				int c=d/g*g*2+a[1]-g;
				if(c>a[n]) cout<<0<<"\n";
				else cout<<n-(d/g*2-1)<<"\n";
			}
			continue;
		}
		cout<<0<<"\n";
	}
	return 0;
}
//CCF_NOI is the best in the world.
//I love CCF_NOI,please give me more AC.
//AC AC AC AC AC AC AC AC AC AC AC AC AC.
//^w^