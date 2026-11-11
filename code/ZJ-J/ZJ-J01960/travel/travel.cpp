#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2,a[5]={1,1,1,2,2};//p:ее╨е 
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(p1==p2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(a[s1[2]-'A']==a[s2[2]-'A'])cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
