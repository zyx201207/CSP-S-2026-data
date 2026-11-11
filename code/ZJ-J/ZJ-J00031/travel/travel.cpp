#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int axiang;
	int bxiang;
	string awei;
	string bwei;
	cin>>axiang>>awei>>bxiang>>bwei;
	if(axiang!=bxiang){
		cout<<"0000";
		return 0;
	}
	if((awei[0]!=bwei[0])||(awei[1]!=bwei[1])){
		cout<<"1000";
		return 0;
	}
	if((awei[2]<='C'&&bwei[2]>'C')||(awei[2]>'C'&&bwei[2]<='C')){
		cout<<"1100";
		return 0;
	}
	if((awei[2]=='A'&&bwei[2]=='B')||(awei[2]=='B'&&(bwei[2]=='A'||bwei[2]=='C'))||(awei[2]=='C'&&bwei[2]=='B')||(awei[2]=='D'&&bwei[2]=='F')||(awei[2]=='F'&&bwei[2]=='D')){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1110";
		return 0;
	}
	return 0;
}
