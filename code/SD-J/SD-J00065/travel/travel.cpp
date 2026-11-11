#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b=true;
	if(c1!=c2)
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	if(c1==c2)
	{
		cout<<1;
		for(long long int i=0;i<s1.size()-1;i++)
		{
			if(s1[i]-'0'!=s2[i]-'0')
			{
				cout<<0;
				cout<<0;
				cout<<0;
				b=false;
				break;
			}
		}
		if(b==true)
		{
			cout<<1;
			if(((s1[s1.size()-1]=='A'||s1[s1.size()-1]=='B'||s1[s1.size()-1]=='C')&&(s2[s2.size()-1]=='D'||s2[s2.size()-1]=='E'))||((s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C')&&(s1[s1.size()-1]=='D'||s1[s1.size()-1]=='E')))
			{
				cout<<0;
				cout<<0;
			}
			else
			{
				cout<<1;
				if(s1[s1.size()-1]+1==s2[s2.size()-1]||s1[s1.size()-1]==s2[s2.size()-1]+1) cout<<1;
				else cout<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
