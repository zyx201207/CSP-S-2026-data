#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>s2>>t1>>t2;
	if(s1!=s2)cout<<"0000";
	else
	{
		cout<<"1";
		if(s2[2]!=t2[2]) cot<<"00";
		else
		{
			cout<<"1";
			if(s2[2]=='0' and t2[2]=='F') or (s2[2]=='F' and t2[2]=='0') or (abs t2[2]-s2[2])==1 and t2[2]='0' and s2[2]='0' cout<<"1";
		}
	}
	return 0;
}
