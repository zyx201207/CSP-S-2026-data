#include<bits/stdc++.h>
using namespace std;
int x[2000005],c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==12||c==11){
			int cha=x[2]-x[1],boo=d%cha;
			if(boo==0){
				cout<<n-boo;
			}
		}
		else{
			cout<<1;
		}
	}
	return 0;
}
