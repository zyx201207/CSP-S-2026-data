#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int bi=0,di=0;
bool t=0,f=0,z=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		z=1;
	}
	else cout<<0;
	if(b[0]+b[1]==d[0]+d[1] && z){
		cout<<1;
		f=1;
	}
	else cout<<0;
	bi=b[2]-'A'+1;
	di=d[2]-'A'+1;
	if(((bi<=3 && di<=3)||(bi>3 && di>3)) && f && z){
		cout<<1;
		t=1;
	}
	else cout<<0;
	if(abs(bi-di)==1 && t && f && z)cout<<1;
	else cout<<0;
	cout<<endl;
	return 0;
}
