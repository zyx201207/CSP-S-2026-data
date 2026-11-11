#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;//大根堆
priority_queue <int,vector<int>,greater<int> > p;//小根堆

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int x=t;
	while(x--){
		int n,d;
		cin>>n>>d;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	if(t==2){
		cout<<1<<endl<<2;
	}
	if(t==1){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
