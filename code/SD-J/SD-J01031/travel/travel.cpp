#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}
	cout<<(c1==c2?"1":"0");
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		if(s1[2]=='A'){
			if(s2[2]=='B')cout<<"11";
			else if(s2[2]=='C')cout<<"10";
			else cout<<"00";
		}
		if(s1[2]=='B'){
			if(s2[2]=='B'||s2[2]=='C')cout<<"11";
			else cout<<"00";
		}
		if(s1[2]=='C'){
			if(s2[2]=='B')cout<<"11";
			else if(s2[2]=='A')cout<<"10";
			else cout<<"00";
		}
		if(s1[2]=='E'){
			if(s2[2]=='F')cout<<"11";
			else cout<<"00";
		}
		if(s1[2]=='F'){
			if(s2[2]=='E')cout<<"11";
			else cout<<"00";
		}
	}
	else cout<<"000";
	cout<<'\n';
	return 0;
} 
