# include <bits/stdc++.h>
using namespace std;
int a[30];
int b[30];
char c[30];
char d[30];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s1;
	if(c1==c2)
	{
		cout<<"1";
	}
	else if(c1!=c2)
	{
		cout<<"0";
	}
	for(int i=0;i<2;i++)
	{
		if(s1[i]<='9'&&s1[i]>='0')
		{
			a[i]=s1[i];
		}
		if(s2[i]<='9'&&s2[i]>='0')
		{
			b[i]=s2[i];
		}
	}
	int flag=0;
	for(int i=1;i<=2;i++)
	{
		if(a[i]==b[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"1";
	}
	else if(flag==0)
	{
		cout<<"0";
	}
	for(int i=0;i<3;i++)
	{
		if(s1[i]<='F'&&s1[i]>='A')
		{
			c[i]=s1[i];
		}
		if(s2[i]<='F'&&s2[i]>='A')
		{
			d[i]=s2[i];
		}
	}
	for(int i=1;i<=1;i++)
	{
		if(c[i]=='D'||c[i]=='F')
        {
            if(d[i]=='D'||c[i]=='F')
            {
                cout<<"1"<<"1";
            }
            else
            {
                cout<<"1"<<"0";
            }
        }
        else if(c[i]=='A'||c[i]=='B'||c[i]=='C')
        {
            if(d[i]=='A'||d[i]=='B'||d[i]=='C')
            {
                cout<<"1";
                if(c[i]=='A'&&d[i]=='B'||d[i]=='A'&&c[i]=='B'||c[i]=='B'&&d[i]=='C'||d[i]=='B'&&c[i]=='C')
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
                cout<<"0";
            }
        }
        else
        {
            cout<<"0"<<"0";
        }
	}
	return 0;
}
