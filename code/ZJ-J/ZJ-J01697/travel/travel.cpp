#include<bits/stdc++.h>
using namespace std;
string a,s,b,ss,x="",y="";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>ss;
	if(a==b)
	{
		cout<<'1';
		for(int i=0;i<s.size()-1;i++)x+=s[i];
		for(int i=0;i<ss.size()-1;i++)y+=ss[i];
		if(x==y)
		{
			cout<<'1';
			char c=s[s.size()-1],d=ss[ss.size()-1];
			if((c=='A'||c=='B'||c=='C')&&(d=='D'||d=='F'))cout<<"00";
			else if((d=='A'||d=='B'||d=='C')&&(c=='D'||c=='F'))cout<<"00";
			else 
			{
				cout<<"1";
				if(c=='A'&&d=='B')cout<<"1";
				else if(c=='B'&&d=='A')cout<<"1";
				else if(c=='B'&&d=='C')cout<<"1";
				else if(c=='C'&&d=='B')cout<<"1";
				else if(c=='D'&&d=='F')cout<<"1";
				else if(c=='F'&&d=='D')cout<<"1";
				else cout<<"0";
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
