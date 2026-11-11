#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,b,n,d,t;cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			b=j;
		}
		if(a[2]-a[1]==a[3]-a[2]&&a[4]-a[3]==a[3]-a[2]){
			int f=a[2]-a[1];
			if(f<0){
				int e=0-f;
			}
			cout<<b-d/f-1;
		}
	}
	return 0;
}
