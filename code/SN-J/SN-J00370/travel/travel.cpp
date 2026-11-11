#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	scanf("%02d %02d%c %02d %02d%c",&a,&b,&e,&c,&d,&f);
	if(c==a){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c==a&&b==d){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c==a&&b==d&&65<=e&&e<=67&&e!=f){
		cout<<"1";
	}else if(c==a&&b==d&&68==e&&f==70&&e!=f){
		cout<<"1";
	}else if(c==a&&b==d&&68==f&&e==70&&e!=f){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c==a&&b==d&&65<=e&&e<=67&&65<=f&&f<=67&&e!=f&&(e-1)==f){
		cout<<"1";
	}else if(c==a&&b==d&&65<=e&&e<=67&&65<=f&&f<=67&&e!=f&&(e+1)==f){
		cout<<"1";
	}else if(c==a&&b==d&&68==e&&f==70&&e!=f&&(e+1)==f){
		cout<<"1";
	}else if(c==a&&b==d&&68==e&&f==70&&e!=f&&(e-1)==f){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

