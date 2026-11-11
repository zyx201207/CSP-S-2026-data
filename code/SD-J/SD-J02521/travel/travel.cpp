#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	char e,f;
		cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	e=b[1];
	f=d[1];
	if(e==f){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	e=b[2];
	f=d[2];
	if(int(e)<68&&int(f)<68){
		cout<<"1";
		if((int(e)-int(f)==-1)||(int(e)-int(f)==1)){
			cout<<"1";
		}else cout<<"0";
	}else if(int(e)>67&&int(f)>67){
		cout<<"11";
	}else cout<<"00";
	return 0;
} 
