#include<bits/stdc++.h>
using namespace std;
int x[1000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int h=x[2]-x[1];
		int y=d/h;
		int ans=(n-2*y+1)*(y-1)+(y-1)*(y-2)/2;
		cout<<ans<<endl;
	}
	return 0; 
}