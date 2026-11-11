#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if((d/(a[2]-a[1]))<=1LL) cout<<"0\n";
		else cout<<(n-((d/(a[2]-a[1]))*2))+1<<"\n";
	}
	return 0;
}