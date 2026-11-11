#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	int c,t,x[1000000];
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int gc=x[2]-x[1];
		if(d<gc*2) {
			cout<<"0"<<endl;
			continue;
		}
		int ds=d/gc;
		int wt=ds*2-1;
		int ans=0;
		for(int i=1;i+wt<=n;i++){
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
