#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4,ans="";
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<"0000";
		return 0;
	}
	ans+="1";
	if(c2[0]==c4[0]&&c2[1]==c4[1]) ans+="1";
	else{
		cout<<"1000";
		return 0;
	}
	if(c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C') ans+="1";
	else if(c2[2]>='D'&&c2[2]<='E'&&c4[2]>='D'&&c4[2]<='E') ans+="1";
	else{
		cout<<"1100";
		return 0;
	}
	if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
		ans+="1";
		cout<<ans;
	}
	else cout<<"1110";
	return 0;
}
