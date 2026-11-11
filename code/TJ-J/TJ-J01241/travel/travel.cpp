#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,sn,s1,s1n;
	cin>>s>>sn>>s1>>s1n;
	if(s==s1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string new_s="",new_s1="";
	new_s+=sn[0];
	new_s+=sn[1];
	new_s1+=s1n[0];
	new_s1+=s1n[1];
//	cout<<","<<new_s<<" "<<new_s1<<",";
	if(new_s==new_s1) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char c=sn[2],c1=s1n[2];
	if((c=='A'||c=='B'||c=='C')&&(c1=='A'||c1=='B'||c1=='C')){
//		cout<<","<<c<<" "<<c1<<",";
		cout<<1;
	}
	else if(c=='D'||c=='F'&&c1=='D'||c1=='F'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(c=='D'&&c1=='F'||c=='F'&&c1=='D'){
		cout<<1;
	}
	else if(c=='A'&&c1=='B'||c=='B'&&c1=='A'||c=='B'&&c1=='C'||c=='C'&&c1=='B'){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
