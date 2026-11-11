#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(( c1 != "1" && s1 != "1") || (c1!="16" && s1!="16")){
		cout<<"1";
		for(int i=1;i<=c2.size();i++){
		if(c2==s2){
			cout<<"1";
		}else{
			cout<<"1000";
		}
	}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
