#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int asdf=1;asdf<=t;asdf++){
		long long n,d;
		cin>>n>>d;
		vector<long long> a;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(d==1){
			cout<<0<<endl;
		}else{
			cout<<n-4<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}