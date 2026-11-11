#include<bits/stdc++.h>
using namespace std;
string t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		t[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			t[1]='1';
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				{
					t[2]='1';
					if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
					{
						t[3]='1';
					}else{
						t[3]='0';
						
					}
				}else{
					t[2]='0';
					t[3]='0';
				}
			}
			if(s1[2]=='D'||s1[2]=='F')
			{
				if(s2[2]=='D'||s2[2]=='F')
				{
					t[2]='1';
					t[3]='1';
				}else{
					t[2]='0';
					t[3]='0';
				}
			}
		}else{
			t[1]='0';
			t[2]='0';
			t[3]='0';
		}
		
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=3;i++)
	{
		cout<<t[i];
	}
	return 0;
}
