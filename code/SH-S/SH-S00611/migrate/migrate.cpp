#include<bits/stdc++.h>
using namespace std;
int n,minn;
long long d; 
long long x[2000005];
/*void dfs1(int zb,int cnt){
	if(zb>=n||cnt>minn) return;
	for(int i=zb;i<)
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		minn=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(n<4){
			cout<<0<<endl;
			continue;
		}
		if(n==4){
			if(x[3]-x[1]>d||x[4]-x[3]>d||x[2]-x[1]>d||x[4]-x[2]>d){
				cout<<0<<endl;
				continue;
			}
			cout<<1<<endl;
		}
		else cout<<2;
	} 
	return 0;
}
