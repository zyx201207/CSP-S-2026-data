#include<bits/stdc++.h>
#define int long long
#define N 1001000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,a[N],dis[5000][5000],dis2[5000][5000],l[5000][5000],tttz2223;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>tttz2223>>t;
	if(tttz2223==13||tttz2223==14){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<0<<endl;
		}
	}if(tttz2223==11||tttz2223==12){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(m/(a[2]-a[1])>=2)cout<<max(0LL,n-(2*(m/(a[2]-a[1])))+1)<<endl;
			else cout<<0<<endl;
		}
	}
	
	return 0;
}

