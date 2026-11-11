#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a,b,c,d;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(s1[0]-'0')*10+(s1[1]-'0');
	c=(c2[0]-'0')*10+(c2[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==c){
		cout<<'1'<<' ';
		if(b==d){
			if(s1[1]==s2[1]) cout<<'1'<<' ';
			else cout<<'0'<<' ';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<'1'<<' ';
			}
			else cout<<'0'<<' ';
			if(abs(s1[2]-s2[2]==1)|| (s1[2]=='D'&&s2[2]=='F') || (s2[2]=='D'&&s1[2]=='F') ){
				cout<<'1'<<' ';
			}
			else cout<<'0'<<' ';
		}
		else cout<<'0'<<' ';
	}
	else cout<<'0'<<' ';
	return 0;
}
