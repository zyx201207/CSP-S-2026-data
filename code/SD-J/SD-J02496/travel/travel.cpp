#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f=1;
	//ÔÚÍ¬che 
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			if(s1[2]=='A')
			{
				if(s2[2]=='B'||s2[2]=='C')
				{
					cout<<"1";
					if(s2[2]=='B')
					{
						cout<<"1";
						return 0;
					}
					else{
						cout<<"0";
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else if(s1[2]=='B')
			{
				if(s2[2]=='A'||s2[2]=='C')
				{
					cout<<"11";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else if(s1[2]=='C')
			{
				if(s2[2]=='B'||s2[2]=='A')
				{
					cout<<"1";
					if(s2[2]=='B')
					{
						cout<<"1";
						return 0;
					}
					else{
						cout<<"0";
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else if(s1[2]=='D')
			{
				if(s2[2]=='F')
				{
					cout<<"11";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else if(s1[2]=='F')
			{
				if(s2[2]=='D')
				{
					cout<<"11";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
		}
			else{
				cout<<"000";
				return 0;
			}
		}
		else{
			cout<<"0000";
			return 0;
		}
		return 0; 
}
	
	
