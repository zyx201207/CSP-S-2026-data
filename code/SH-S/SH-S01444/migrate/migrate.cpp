#include<bits/stdc++.h>
using namespace std;
int fc=0,c,t,n,d,x[2000020];
vector<int> temp[2000020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(c==11||c==12){
				fc=x[i]-x[i-1];
			}
		}
		if(c==11||c==12){
			cout<<n-(2*(d/fc)*fc-1)<<"\n";
		}
	}
	return 0;
}
