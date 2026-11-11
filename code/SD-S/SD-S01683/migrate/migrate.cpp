#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d==(x[2]-x[1])*2){
			cout<<1<<'\n';
		}
	}
	return 0;
}
