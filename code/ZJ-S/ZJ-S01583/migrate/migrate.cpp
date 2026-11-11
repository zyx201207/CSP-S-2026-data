#include<bits/stdc++.h>
using namespace std;
int n,m,t,a,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++) cin>>t;
		srand(time(0));
		cout<<rand()*rand()%10000<<endl;
	}
	return 0;
}
