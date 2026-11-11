#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool zy(char c)
{
	if(c=='A'||c=='B'||c=='C') return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else
	{
		cout<<"0000";
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else
	{
		cout<<"000";
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(zy(s1[2])&&zy(s2[2])||!zy(s1[2])&&!zy(s2[2])) cout<<"1";
	else
	{
		cout<<"00";
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<"1";
	else cout<<"0";
	fclose(stdin);fclose(stdout);
	return 0;
}
