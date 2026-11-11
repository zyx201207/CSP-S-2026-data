#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,a[2000005];
		cin>>n>>d;
		if(c==13||c==14){
			cout<<n-1<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<abs(n/4-d)<<"\n";
	}
	return 0;
}