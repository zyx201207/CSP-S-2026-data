#include<bits/stdc++.h>
using namespace std;
string c[3],s[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}