#include<bits/stdc++.h>
using namespace std;
string a,b;
string s1,s2;
string x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	x=s1[2],y=s2[2];
	if(a==b){
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";		
	}
	else{
		cout<<"000";
		return 0;
	}
	if(x=="D"&&y=="F"||y=="D"&&x=="F"){
		cout<<"11";
		return 0;
	}
	if(x=="D"&&y!="F"||x=="F"&&y!="D"||y=="D"&&x!="F"||x!="D"&&y=="F"){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(x=="B"||y=="B"){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
