#include<bits/stdc++.h>
using namespace std;
int c,T,x[2000005],idx;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<min((x[n]+x[1])/2,(x[n]-x[1])/2)<<endl;
	}
	return 0;
} 
