#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	int n1=(s1[0]-'0')*10+s1[1]-'0',n2=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2&&n1==n2)cout<<1;
	else cout<<0;
	if(c1==c2&&n1==n2&&((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))))
		cout<<1;
	else cout<<0;
	if(c1==c2&&n1==n2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
		cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
