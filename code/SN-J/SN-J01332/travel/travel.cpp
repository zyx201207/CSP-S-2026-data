#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) cout<<1;
	else cout<<0;
	if(c1==s1 && c2[0]==s2[0] && c2[1]==s2[1])
	{
		cout<<1;
	
	}
	else cout<<0;
	if(c1==s1 && c2[0]==s2[0] && c2[1]==s2[1] &&(int(c2[2])<=67 && int(s2[2])<=67) || (int(c2[2])>67 && int(s2[2])>67) ) cout<<1;
	else cout<<0;
	if(c1==s1 && c2[0]==s2[0] && c2[1]==s2[1] &&(int(c2[2])<=67 && int(s2[2])<=67) || (int(c2[2])>67 && int(s2[2])>67))
	{
		if(abs(int(c2[1]-s2[1]+c2[0]-s2[0]))==1 || (abs(int(c2[2]-s2[2]))==1)) cout<<1;
		else cout<<0;
	}
	else cout<<0;

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
