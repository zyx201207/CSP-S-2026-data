#include <bits/stdc++.h>
using namespace std;
long long n[10000005],d[000000005];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		vector<int> a(n[i]);
		for(int j=0;j<n[i];j++){
			cin>>a[j];
		}
		if(n[i]%2==0) cout<<"1"<<'\n';
		else if(n[i]%2==1&&a[0]<0) cout<<0<<'\n';
		else if(n[i]%2==1&&a[0]>0)cout<<2<<'\n';
		else cout<<99<<'\n';
	}
	
	return 0;
}
