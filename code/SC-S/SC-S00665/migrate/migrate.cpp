#include<bits/stdc++.h>
using namespace std;
long long f[2000010];
int a[2000010];
map<int,long long>mp; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		mp.clear();
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]++;
		}
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		if(n<=d){
			cout<<0<<"\n";
			continue;
		}
		if(a[n]-a[1]<=d*2&&n>=5){
			cout<<0<<"\n";
			continue;
		}
		d++;
		int ans=0;
		for(int i=1;i+3<=n;i++){
			if(mp[a[i]+d]>=1){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
