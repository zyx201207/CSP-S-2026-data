#include<iostream>
#define endl '\n'
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	int a1,a2;
	a1=int(s1[0]-'0')*10+(s1[1]-'0');
	a2=int(s2[0]-'0')*10+(s2[1]-'0');
	if(a1==a2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char b1=s1[2],b2=s2[2];
	if((b1=='A'&&b2=='B')||(b1=='A'&&b2=='C')||(b1=='B'&&b2=='C')||(b1=='B'&&b2=='A')||(b1=='C'&&b2=='A')||(b1=='C'&&b2=='B')||(b1=='D'&&b2=='F')||(b1=='F'&&b2=='D'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((b1=='A'&&b2=='B')||(b1=='B'&&b2=='C')||(b1=='B'&&b2=='A')||(b1=='C'&&b2=='B')||(b1=='D'&&b2=='F')||(b1=='F'&&b2=='D'))cout<<1;
	else{
		cout<<"0";
		return 0;
	}
	return 0;
 } 
