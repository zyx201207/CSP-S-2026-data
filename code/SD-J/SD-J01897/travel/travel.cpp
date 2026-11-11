#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	bool fl2=true;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			fl2=false;
			break;
		}
	}
	if(fl2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(abs((s1[2]-'A')-(s2[2]-'A'))==1) cout<<"1";
	else cout<<"0";
	return 0;
}
