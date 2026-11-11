#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
	char a1,b1;
	string a2[4],b2[4];
    cin>>a1>>a2[2]>>b1>>b2[2];
	if(a1=b1){
		cout<<1;
	}
	else{
		cout<<0;
	}

	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
}
	else{
		cout<<0;
	}
	
	return 0;
}
