#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)
	{
		cout<<"1";
		if(c1.substr(0,2)==c2.substr(0,2))
		{
			cout<<"1";
			int t1=c1[2]-'A'+1,t2=c2[2]-'A'+1;
			if((t1<=3&t1>=1&&t2<=3&t2>=1)||(t1<=5&t1>=4&&t2<=5&t2>=4))
			{
				cout<<"1";
				if(max(t1,t2)-min(t1,t2)==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
} 
