#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long d,n,a[maxn];
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int m=a[2]-a[1],f=1;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=m){
				f=0;
			};
		}
		if(f=1){
		}
	}
	return 0;
}
