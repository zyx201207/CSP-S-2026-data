#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1,s2;
	int a,b,c,d;
	cin>>a>>b>>s1>>c>>d>>s2;
	if(a!=c) cout<<"0000";
	else if (b!=d) cout<<"1000";
	else if (s1=='A'&&s2=='D'||s1=='A'&&s2=='E'||s1=='B'&&s2=='D'||s1=='B'&&s2=='E'||s1=='C'&&s2=='D'||s1=='C'&&s2=='E'||s2=='A'&&s1=='D'||s2=='A'&&s1=='E'||s2=='B'&&s1=='D'||s2=='B'&&s1=='E'||s2=='C'&&s1=='D'||s2=='C'&&s1=='E') cout<<"1100";
	else if ((s1=='A'&&s2=='B')||(s1=='B'&&s2=='A')||(s1=='B'&&s2=='C')||(s1=='C'&&s2=='B')||(s1=='D'&&s2=='E')||(s1=='E'&&s2=='D')) cout<<"1111";
	else cout<<"1110";
    fclose(stdin);
	fclose(stdout);	
	return 0;
}
