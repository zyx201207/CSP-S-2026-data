#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	char c=a2[2],d=b2[2];//ап 
	if(a1==b1) cout<<"1";
	else{
		cout<<"0000";
		return 0;	
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]) cout<<"1";
	else cout<<"0";
	if((c<='C'&&d<='C'||c>='D'&&d>='D')&&a2[0]==b2[0]&&a2[1]==b2[1])
	cout<<"1";
	else cout<<"0";
	if(c==d&&(a2[1]+1==b2[1]||a2[1]-1==b2[1]||a2[1]=='1'&&a2[2]=='0'&&b2[2]=='9'||b2[1]=='1'&&b2[2]=='0'&&a2[2]=='9'))
	cout<<"1";
	else if(a2[0]==b2[0]&&a2[1]==b2[1]&&(c<='C'&&d<='C'||c>='D'&&d>='D')&&(c==d+1||c==d-1))
	cout<<"1";
	else cout<<"0";
	return 0;
} 
