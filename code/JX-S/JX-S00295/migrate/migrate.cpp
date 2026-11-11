#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,b;
	cin>>b>>t;
	for(int j=0;j<t;j++){
		int n;
		long long a;
		cin>>n>>a;
		vector<long long>d(n);
		for(int i=0;i<n;i++){
			cin>>d[i];
		}
		vector<long long>f(n+5,0);
		for(int i=0;i<n-1;i++){
			f[i]=d[i+1]-d[i];
		}
		vector<long long>e(n+5,0);
		for(int i=1;i<n-2;i++){
			e[i]=f[i]+f[i-1]+f[i+1];
		}
		int ans=0;
		for(int i=0;i<n-2;i++){
			if(e[i]==a+1)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
