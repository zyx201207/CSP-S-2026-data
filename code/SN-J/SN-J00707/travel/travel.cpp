//dujingqi jiandafuzhong SN-J00707
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int t,s,c;
	if(c1==c2){
		cout<<"1";
		t=1;
	}else{
		cout<<"0";
		t=0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&t==1){
		cout<<"1";
		s=1;
	}else{
		cout<<"0";
		s=0;
	}
	
	if(s1[2]<=67&&s2[2]<=67&&t==1&&s==1){
		cout<<"1";
		c=1;
	}else if(s1[2]>=67&&s2[2]>=67&&t==1&&s==1){
		cout<<"1";
		c=1;
	}else{
		cout<<"0";
		c=0;
	}
	
	if(s1[2]==s2[2]+1||s1[2]==s2[2]-1&&t==1&&s==1&&c==1){
		cout<<"1";
	}else cout<<"0";
	return 0;
}
