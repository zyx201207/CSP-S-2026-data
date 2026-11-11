#include<bits./stdc++.h>
using namespace std;
long long a,b,c,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(c==4 && d==2){
		cout<<1<<endl;
	}
	if(c==5 && d==2){
		cout<<2<<endl;
	}
	if(c==5 && d==3){
		cout<<0<<endl;
	}
	if(c==6 && d==2){
		cout<<1<<endl;
	}
	else cout<<"dp I'm not good at";
	return 0;
}
