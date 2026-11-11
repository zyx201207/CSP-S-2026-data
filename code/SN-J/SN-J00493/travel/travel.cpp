#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char s1[4],s2[4];
int c1,c2;
char l=0;
int main(){
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[1]==s2[1])
		{
			cout<<"1";
			if(s1[2]<='C'and s2[2]<='C' or s1[2]>'C'and s2[2]>'C')
			{	
				cout<<"1";
				if(s1[2]-s2[2]!=1 or s2[2]-s1[2]!=1 )
				{
					cout<<"0";
				}else if((s1[1]+s1[0])-(s2[1]+s2[1])==1)
				{
					cout<<"0";	
				}else{
					cout<<"1";
				}
			}else{
			cout<<"0";
			cout<<"0";
			}
		}else
		{
			cout<<"0";
			cout<<"0";
			cout<<"0";
		}
		
		
	}else
	{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}

	return 0;
}


 
