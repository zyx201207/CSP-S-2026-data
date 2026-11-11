#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>s2[2])swap(s1[2],s2[2]);
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	//
	//x="A",y="B";
	if(s1[2]+1==s2[2])cout<<1;
	else cout<<0;
	return 0;
} 
//Trick||Treat!
