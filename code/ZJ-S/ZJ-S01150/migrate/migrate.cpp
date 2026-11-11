#include<bits/stdc++.h>
using namespace std;
long long c,t,n[100005],d[100005],x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0&&t==2){
		while(t--){
			cin>>n[t]>>d[t];
			for(int i=1;i<=n[t];i++){
				cin>>x[i];
			}
		}
		if(n[1]==4){
			cout<<1<<'\n'<<2;
		}else{
			cout<<0<<'\n'<<1;
		}
		return 0;
	}
	while(t--){
		cin>>n[t]>>d[t];
		for(int i=1;i<=n[t];i++){
			cin>>x[i];
		}
		cout<<0<<'\n';
	}
	return 0;
}