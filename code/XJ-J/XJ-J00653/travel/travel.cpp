#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m;
string s1,s2,c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
			{
				if(abs(s1[2]-s2[2])==1||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
				{
					cout<<"1111"<<endl;
				}
				else
				cout<<"1110"<<endl;
			}
			else
			cout<<"1100"<<endl;
		}
		else
		cout<<"1000"<<endl;
	}
	else
	cout<<"0000"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
