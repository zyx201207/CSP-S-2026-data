#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int island[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(island,0,sizeof(island));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>island[i];
		}
	}
	cout<<"Thanks for CSP!";
	return 0;
}
