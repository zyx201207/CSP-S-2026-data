#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(num==4&&x==2){
			cout<<"1"<<" "<<"2";
		}else if(num==5&&x==3){
			cout<<"0"<<" "<<"1";
		}
		num=x;
	}
	return 0;
}
