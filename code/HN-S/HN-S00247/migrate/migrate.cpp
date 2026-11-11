#include<bits/stdc++.h>
using namespace std;
int c,T;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>a[i];
		cout<<d<<endl;
	}
	return 0;
}
