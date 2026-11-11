#include<bits/stdc++.h>
using namespace std;
char c[10],c1[10],s[10],s1[10];
int l,r,ret,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++) cin>>c[i];
	for(int i=1;i<=3;i++) cin>>c1[i];
	for(int i=1;i<=2;i++) cin>>s[i];
	for(int i=1;i<=3;i++) cin>>s1[i];
	for(int i=1;i<=2;i++)
	{
		l=l*10+(c[i]-'0');
		r=r*10+(s[i]-'0');
		ret=ret*10+(c1[i]-'0');
		ans=ans*10+(s1[i]-'0'); 
	}
	if(l==r)
	{
		cout<<1;
		if(ret==ans)
		{
			cout<<1;
			if((c1[3]-'A'<3&&s1[3]-'A'<3)||(c1[3]-'A'>=3&&s1[3]-'A'>=3))
			{
				cout<<1;
				if(c1[3]-'A'+1==s1[3]-'A'||c1[3]-'A'-1==s1[3]-'A')
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
	else cout<<"0000";
	
	return 0;
}
