#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x1[2000010],v[2000010];
long long x[2000010];
int m=0,mn=0x3f3f3f,cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n-2*d+1;
	}
}
