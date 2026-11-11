#include <bits/stdc++.h>

using namespace std;
const int N=2e6+5;
int c,t,n,d;
int x[N],f[N];
long long jie(int x){
	long long s=1;
	for(int i=1;i<=x;i++){
		s*=i;
	}
	return 1ll*s;
}
long long C(int x,int y){
	return jie(x)/(jie(y)*jie(x-y));
}
int f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int cha=abs(x[1]-x[2]);
			if(cha*2<=d){
				cout<<C(n,2)<<"\n";
			}
			else {
				cout<<"0\n";
			}
		}
	}
	else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<n-1<<"\n";
		}
	}
	return 0;
}
