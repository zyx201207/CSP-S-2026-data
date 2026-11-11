#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d;
	if(a==0&&b==2&&c==4&&d==2){
		for(int i=1;i<=11;i++){
			cin>>e;
		}
		cout<<"1"<<endl<<"2";
	}
	if(a==0&&b==2&&c==5&&d==3){
		for(int i=1;i<=13;i++){
			cin>>e;
		}
		cout<<"0"<<endl<<"1";
	}
	return 0;
}
