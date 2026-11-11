#include<bits/stdc++.h>
using namespace std;
int c,t,a[2100000],b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=4;i++){
			cin>>a[i];
		}
		b=a[2]-a[1]; 
		d=d/b;
		if(d==1){
			cout<<0<<endl;
		}else{
			cout<<n-d-1<<endl;
		}
	}
	return 0;
}
