#include<bits/stdc++.h>
using namespace std;
bool xiang(string c1,string c2)
{
	return (c1==c2);
}
bool pai(string c1,string s1,string c2,string s2)
{
	return ((s1[0]+s1[1])==(s2[0]+s2[1]))&&xiang(c1,c2);
}
bool ce(string c1,string s1,string c2,string s2)
{
	if(pai(c1,s1,c2,s2)==false) return false;
	char a=s1[2],b=s2[2];
	int cnt=0;
	for(char i='A';i<='C';i++)
	{
		if(a==i||b==i) cnt++;
	}
	if(cnt==2||cnt==0) return true;
	if(cnt==1) return false;
}
bool lin(string c1,string s1,string c2,string s2)
{
	if(pai(c1,s1,c2,s2)==0||ce(c1,s1,c2,s2)==0) return false;
	char a=s1[2],b=s2[2];
	int cnt=0;
	for(char i='A';i<='C';i++)
	{
		if(a==i||b==i) cnt++;
	}
	if(cnt==0) return true;
	if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')) return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<xiang(c1,c2)<<pai(c1,s1,c2,s2)<<ce(c1,s1,c2,s2)<<lin(c1,s1,c2,s2);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
