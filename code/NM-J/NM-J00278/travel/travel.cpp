#include<bits/stdc++.h>
using namespace std;
char s1[20];
char s2[20];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    cin>>c1;
    for(int i=0;i<=3;i++)
    {
        cin>>s1[i];
    }
    cin>>c2;
    for(int i=0;i<=3;i++)
    {
        cin>>s2[i];
    }
    if(c1==c1)
    {
    	cout<<"1"<<" ";
	}
	else
	{
		cout<<"0"<<" ";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
    	cout<<"1"<<" ";
	}
	else
	{
		cout<<"0"<<" ";
	}
	if(s1[3]=='A'&&s2[3]=='A'||s1[3]=='A'&&s2[3]=='B'||s1[3]=='A'&&s2[3]=='C'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='B'&&s2[3]=='c'||s1[3]=='B'&&s2[3]=='B'||s1[3]=='C'&&s2[3]=='A'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='C'&&s2[3]=='C'||s1[3]=='D'&&s2[3]=='D'||s1[3]=='D'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='D'||s1[3]=='F'&&s2[3]=='F')
    {
        cout<<"1"<<" ";
    }
    else
	{
		cout<<"0"<<" ";
	}
	if(s1[3]-1==s2[3]||s1[3]+1==s2[3])
    {
        cout<<"1"<<" ";
    }
    else
	{
		cout<<"0"<<" ";
	}
    return 0;

}

