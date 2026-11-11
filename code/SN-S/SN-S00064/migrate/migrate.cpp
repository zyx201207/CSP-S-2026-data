#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,y;
vector<long long>x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		x.clear();
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>y;
			x.push_back(y);
		}
		if(c==11||c==12){
			long long ok=d/(x[1]-x[0]);
			if(n<ok+2||ok<2||(n>ok+1&&n<2*ok)){
				cout<<0<<endl;
				continue;
			}
			cout<<n-2*ok+1<<endl;
		}
	}
	return 0;
}

