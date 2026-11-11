#include<bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>a1>>a2;
	if(s1!=a1){
		cout<<"0000";
	}else if(s2[0]*10+s2[1]!=a2[0]*10+a2[1]){
		cout<<"1000";
	}else if(s2[2]<='C'&&a2[2]>'C'){
//		cout<<char(s2[2])<<char(a2[2]);
	    cout<<"1100";	
	}else if(s2[2]>='D'&&a2[2]<'D'){
		cout<<"1100";
	}else{
		if(s2[2]<='C'&&abs(int(s2[2]-a2[2]))==1){
			cout<<"1111";
		}else if(s2[2]>='D'){
			cout<<"1111";
		}else{
			cout<<"1110";
		}
	}
	return 0;
}
