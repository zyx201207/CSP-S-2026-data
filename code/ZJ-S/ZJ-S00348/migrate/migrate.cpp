#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x[2000005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		cin>>x[i];
		if(m>abs(x[1]-x[n])){
			cout<<0<<"\n";
			continue;
		}
		bool flag=0;
		for(int i=3;i<=n;i++)
		if(x[i]-x[i-1]!=x[i-1]-x[i-2])
		flag=1;
		if(flag==0){
			int v=x[2]-x[1];
			if(v>=m){
				cout<<0<<"\n";
				continue;
			}
			else {
				int a=(m-1)/v;
				int ans=0;
				for(int i=1;i<=a;i++)
				ans+=n-i-1;
				cout<<0<<"\n";
			}
		}
				cout<<0<<"\n";
	}
}