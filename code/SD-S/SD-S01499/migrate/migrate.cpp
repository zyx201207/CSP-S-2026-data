#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,_,add=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1){
				_=min(_,x[i]-x[i-1]);
			}
			if(add==0&&x[i]<0){
				add=-x[i];
			}
		}
		if(add!=0){
			for(int i=1;i<=n;i++){
				x[i]+=add; 
			}
		}/*
		for(int i=1;i<=n;i++){
			
		}*/
		if(_>d){
			cout<<0;
		}
		else{
			cout<<(n*n-1)/d;
		}
		cout<<"\n";
	}
	return 0;
}
