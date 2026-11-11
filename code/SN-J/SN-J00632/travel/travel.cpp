//hezhuchen延安新区第一中学SN-J00632 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1=="16"||s3=="16"||s1=="1"||s3=="1")
	{
		cout<<"0000";
		return 0;
	}
	if(s1!=s3)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		string a;
		a=s2[0]+s2[1];
		string b;
		b=s4[0]+s4[1];
		if(a==b){
			cout<<"1";
			char a1=s2[2];
			char b1=s4[2];
			if((a1=='A'||a1=='B'||a1=='C')&&(b1=='A'||b1=='B'||b1=='C')||(a1=='D'||a1=='F')&&(b1=='D'||b1=='F')){
				cout<<"1";
				if((a1=='A'&&b1=='B')||(a1=='B'&&b1=='A')||(a1=='C'&&b1=='B')||(a1=='B'&&b1=='C')||(a1=='F'&&b1=='D')||(a1=='D'&&b1=='F')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	return 0;
}
