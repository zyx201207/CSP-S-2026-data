#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,b1,d1,ans;
char b2,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<3;i++){
		if(i==2) b2=b[i];
		else b1+=b[i];
	}
	for(int i=0;i<3;i++){
		if(i==2) d2=d[i];
		else d1+=d[i];
	}
	if(a==c) ans+="1";
	else{
		cout<<"0000";
		return 0;
	}
	if(b1==d1) ans+="1";
	else{
		cout<<"1000";
		return 0;
	}
	if(((b2>='A'&&b2<='C')&&(d2>='A'&&d2<='C'))||((b2=='D'&&d2=='F')||(d2=='D'&&b2=='F'))) ans+="1";
	else {
		cout<<"1100";
		return 0;
	}
	if(b2+1==d2||b2-1==d2){
		ans+="1";
		cout<<ans;
	}
	else {
		cout<<"1110";
		return 0;
	}
	return 0;
}
