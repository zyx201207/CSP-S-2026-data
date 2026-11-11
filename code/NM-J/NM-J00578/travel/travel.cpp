#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long cnt=0,flag=0;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=2;i++)
    {
        if(c1[i]==c2[i])
        {
            cnt++;
        }
    }
    if(cnt==3)
    {
        cout<<1;
        flag=1;
    }
    else
    {
        cout<<0;
    }
    int cnt1=0;
    for(int i=0;i<=1;i++)
    {
        if(s1[i]==s2[i])
        {
            cnt1++;
        }
    }
    if(cnt1==2&&flag==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        flag=0;
    }
    if(flag==1)
		if(s1[2]>'C')
			if(s2[2]>'C')
				cout<<1;
			else
				cout<<0;
		else if(s1[2]<'D')
			if(s1[2]<'D')
				cout<<1;
			else
				cout<<0;
		else
			cout<<0;
	else
	{
		cout<<0;
		flag=0;
	}
	if(flag==1)
		if(abs(s1[2]-s2[2])==1)
			if(s1[2]>'C')
				if(s2[2]>'C')
					cout<<1;
				else
					cout<<0;
			else if(s1[2]<'D')
				if(s1[2]<'D')
					cout<<1;
				else
					cout<<0;
			else
				cout<<0;
		else if(s1[2]=='D'&&s2[2]=='F')
			if(s1[2]>'C')
				if(s2[2]>'C')
					cout<<1;
				else
					cout<<0;
			else if(s1[2]<'D')
				if(s1[2]<'D')
					cout<<1;
				else
					cout<<0;
			else
				cout<<0;
		else if(s2[2]=='D'&&s1[2]=='F')
			if(s1[2]>'C')
				if(s2[2]>'C')
					cout<<1;
				else
					cout<<0;
			else if(s1[2]<'D')
				if(s1[2]<'D')
					cout<<1;
				else
					cout<<0;
			else
				cout<<0;
		else
			cout<<0;
	else
		cout<<0;
    return 0;
}
