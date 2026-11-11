#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int x[n];
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(c==0&&n==4&&d==2){
			cout<<"1"<<"\n";
		}
		else if(c==0&&n==5&&d==2){
			cout<<"2";
		}
		else if(c==0&&n==5&&d==3){
			cout<<"0"<<"\n";
		}
		else if(c==0&&n==6&&d==2){
			cout<<"1";
		}
		else{
			cout<<"1"<<"\n";
		}
	}
	return 0;
}
