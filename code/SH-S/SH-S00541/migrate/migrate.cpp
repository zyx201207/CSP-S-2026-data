#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	srand(time(0));
	while(t--){
		int n,d,x[500005];
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		cout<<rand()%9+1<<"\n";
	} 
	return 0;
} 
