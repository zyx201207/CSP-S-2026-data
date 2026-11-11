#include<bits/stdc++.h>
using namespace std;
long long a[2000006],b[2000006];
int main(){
	freopen("crystal.in","a",stdin);
	freopen("crystal.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>a[i]>>b[i];
		cout<<b[1]-a[1]<<"\n";
	}
	return 0;
}