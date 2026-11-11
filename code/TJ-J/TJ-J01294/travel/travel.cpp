#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f(string a)
{
	int l=a.size(),q=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]=='0') continue;
		if(a[i]>='0'&&a[i]<='9')
		{
			q+=a[i]-'0';
			q*=10;
		}
	}
	q/=10;
	return q;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		int a1=f(s1),a2=f(s2);
		if(a1==a2)
		{
			cout<<1;
			int l1=s1.size(),l2=s2.size();
			char w1=s1[l1-1],w2=s2[l2-1];
			if((w1<='C'&&w2<='C')||(w1>'C'&&w2>'C'))
			{
				cout<<1;
				if(w1-w2==1||w2-w1==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
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
