#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;



int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,sb;
	string stra,strb;
	cin>>sa>>sb>>stra>>strb;
	for(int i=0;i<=2;i++)
	{
		
	
	if(sa[0]==stra[0]&&sa[1]==stra[1])
	{
		cout<<1;
		if(sb[0]==strb[0]&&sb[1]==strb[1])
		{
			cout<<1;
			if((sb[2]=='A'&&strb[2]=='B'||strb[2]=='C')||(sb[2]=='B'&&strb[2]=='A'||strb[2]=='C')||(sb[2]=='C'&&strb[2]=='B'||strb[2]=='A')||(sb[2]=='D'&&strb[2]=='F')||(sb[2]=='F'&&strb[2]=='D'))     
			{
				cout<<1;
				if((sb[2]-'0')-(strb[2]-'0')<=1)
				{
					cout<<1;
					break;
				}
				else
				{
					cout<<"0";
					break;
				}
			}
			else
			{
				cout<<"00";
				break;
			}
		}
		else
		{
			cout<<"000";
			break;
		}
	}
	else
	{
		cout<<"0000";
		break;
	}
	}
	return 0;
}


