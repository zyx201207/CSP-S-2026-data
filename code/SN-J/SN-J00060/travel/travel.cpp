#include<iostream> 
#include<vector> 
#include<cmath> 
#include<algorithm> 
#include<map> 
#include<set> 
#include<cstdio>
#include<string> 
#include<cstring>
using namespace std;
int a,b;
string a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;	
	} 
	if(a1[0]==b1[0]&&a1[1]==b1[1]) cout<<1;
	else{
		cout<<"000";
		return 0;	
	}
	if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')){
		if(a1[2]=='A'&&b1[2]=='C') cout<<"10";
		if(a1[2]=='C'&&b1[2]=='A') cout<<"10";
		else cout<<"11";
	}
	else if((a1[2]=='E'||a1[2]=='F')&&(b1[2]=='E'||b1[2]=='F')) cout<<11;
	else cout<<"00";
	return 0;
}
