#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	a1=' '+a1;
	b1=' '+b1;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a1[1]==b1[1]&&a1[2]==b1[2]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int a2,b2;
	a2=int(a1[3]);
	b2=int(b1[3]);
	if(a2<=67&&b2<=67||a2>=68&&b2>=68){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(b2-a2)==1||a2==68&&b2==70||b2==68&&a2==70){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
