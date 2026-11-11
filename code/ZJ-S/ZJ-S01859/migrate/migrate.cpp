#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			sum+=x;
		}
		if(sum==0){
			cout<<0<<endl;
		}
		else if(sum==-1){
			cout<<1<<endl;
		}
		else{
			cout<<(sum-n*d)/2<<endl;
		}
	}
	return 0;
}
