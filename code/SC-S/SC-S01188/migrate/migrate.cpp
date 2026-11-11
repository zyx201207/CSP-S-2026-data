#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("crystal.in","a",stdin);
	freopen("crystal.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<a[2]-a[1]<<"\n";
	}
	return 0;
}

