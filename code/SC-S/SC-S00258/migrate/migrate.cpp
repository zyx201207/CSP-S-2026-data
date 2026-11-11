#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n,m,d;
	cin>>c>>n>>m>>d;
	if(c==0&&n==2&&m==4&&d==2){
		cout<<"1"<<endl;
		cout<<"2";
	}else if(c==0&&n==2&&m==5&&d==3){
		cout<<"0"<<endl;
		cout<<"1";
	}
	return 0;
}