#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char n[100];
	for(int i=1;i<=10;i++){
		cin>>n[i];
	}
	if(n[1]+n[2]!=n[6]+n[7]){
		cout<<"0000";
		return 0;
	}
	else if(n[4]+n[3]!=n[8]+n[9]){
	    cout<<"1000";
	    return 0;
	}
	else if(n[5]=='A'&&n[10]=='C'){
		cout<<"1100";
		return 0;
	}
	else if(n[5]+1!=n[10]&&n[5]!=n[10]+1){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
	return 0;
}
