#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0] or c1[1]!=c2[1])cout<<"0000";
	else if(s1[0]!=s2[0] or s1[1]!=s2[1])cout<<"1000";
	else if((s1[2]<='C' && s2[2]>='D') or (s1[2]>='D' && s2[2]<='C'))cout<<"1100";
	else if(abs(s1[2]-s2[2])>1)cout<<"1110";
	else cout<<"1111";
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
