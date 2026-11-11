#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int c11,c22;
int s11,s22;
char op1,op2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	op1=s1[2];
	op2=s2[2];
	for(int i=0;i<c1.size();i++)
	{
		c11*=10;
		c11+=c1[i]-'0';
	}
	for(int i=0;i<c2.size();i++)
	{
		c22*=10;
		c22+=c2[i]-'0';
	}
	for(int i=0;i<s1.size()-1;i++)
	{
		s11*=10;
		s11+=s1[i]-'0';
	}
	for(int i=0;i<s2.size()-1;i++)
	{
		s22*=10;
		s22+=s2[i]-'0';
	}
	if(c11==c22)
	{
		cout<<'1';
			if(s11==s22)
			{
				cout<<'1';
				if(((op1>='A'&&op1<='C')&&(op2>='A'&&op2<='C'))||((op1>='D'&&op1<='E')&&(op2>='D'&&op2<='E')))
				{
					cout<<'1';
					if(op1==op2-1||op1==op2+1)
					{
						cout<<'1';
					}else cout<<'0';
				}else cout<<'0'<<'0';
			}else cout<<'0'<<'0'<<'0';
	}else cout<<'0'<<'0'<<'0'<<'0';
//	cout<<c11<<" "<<c22<<'\n'<<s11<<' '<<s22<<'\n'<<op1<<' '<<op2<<'\n';
	
	return 0;
}