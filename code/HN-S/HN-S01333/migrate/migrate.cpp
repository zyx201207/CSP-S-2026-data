#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
vector<int> x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int ans=0;
	for (int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		x.clear();
		for (int j=1;j<=n;j++){
			int d;
			cin>>d;
			x.push_back(d);
		}
		for (int z=0;z<n;z++){
			for (int o=z+1;o<n;o++){
				if((x[o]-x[z])%d==1&&(x[o]-x[z])>d){
					ans++;
					cout<<x[o]<<" "<<x[z]<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
