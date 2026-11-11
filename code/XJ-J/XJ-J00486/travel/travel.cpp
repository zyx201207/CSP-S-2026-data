#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,cx2,wz1,wz2;
	int flag=0;
	cin>>cx1>>wz1>>cx2>>wz2;
	if(cx1==cx2) 
	{
		cout<<'1';
		string t1,t2;
		for(int i=0;i<=1;i++)
		{
			t1+=wz1[i];
			t2+=wz2[i];
		}
		if(t1==t2)
		{
			cout<<'1';
			if((wz1[2]=='A'&&  (wz2[2]=='A'||wz2[2]=='B'||wz2[2]=='C')) || (wz1[2]=='B'&&  (wz2[2]=='A'||wz2[2]=='B'||wz2[2]=='C')) || (wz1[2]=='C'&&  (wz2[2]=='A'||wz2[2]=='B'||wz2[2]=='C'))  ||  ((wz1[2]=='D' && wz2[2]=='F')  ||  (wz1[2]=='F' && wz2[2]=='D')))
			{
				cout<<'1';
				if((wz1[2]+1==wz2[2] || wz2[2]+1==wz1[2])  &&  ((wz1[2]!='C' && wz2[2]!='D')  ||  (wz1[2]!='D' && wz2[2]!='C')))
				{
					cout<<'1';
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
