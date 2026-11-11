#include<iostream>
#include<cmath>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0 0 0 0";
		return 0;
	}
	cout<<"1 ";
	c1=((s1[0]-'0')*10+s1[1]-'0');
	c2=((s2[0]-'0')*10+s2[1]-'0');
//	cout<<(s1[0]-'0')<<" "<<s1[0]-'0'<<endl;
	if(c1==c2){ 
		cout<<"1 ";
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				cout<<"1 ";
			else
				cout<<"0 ";
		}
		if(s1[2]=='D'||s1[2]=='E'){
			if(s2[2]=='D'||s2[2]=='E')
				cout<<"1 ";
			else
				cout<<"0 ";
		}
	}
	else cout<<"0 0 ";
	if(abs(c1-c2)==1&&abs(s1[2]-s2[2])==0)
		cout<<1;
	else if(abs(c1-c2)==0&&abs(s1[2]-s2[2])==1&&!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))
		cout<<1;
	else
		cout<<0;
	
	return 0;
}
