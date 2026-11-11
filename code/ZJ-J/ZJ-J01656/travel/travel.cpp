#include<bits/stdc++.h>
using namespace std;
const char p1[]={'0','A','B','C'};
const char p2[]={'0','D','E','F'};
string s1,s2,t1,t2;
int pd(char a,char b)
{
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
	    if(a==p1[i]&&b==p2[j]) return 0;
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
	    if(b==p1[i]&&a==p2[j]) return 0;
	return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>t1>>s2>>t2;
	if(s1==s2)
	{
		cout<<1;
		int x=(t1[0]-'0')*10+t1[1]-'0',y=(t2[0]-'0')*10+t2[1]-'0';
		if(x==y)
		{
			cout<<1;
			if(!pd(t1[2],t2[2])) cout<<"00"<<endl;
			  else 
			  {
			  	if(t1[2]=='A'&&t2[2]=='B'||t1[2]=='B'&&t2[2]=='A'||t1[2]=='C'&&t2[2]=='B'||t1[2]=='B'&&t2[2]=='C') cout<<"11"<<endl;
			  	  if(t1[2]=='D'&&t2[2]=='E'||t1[2]=='E'&&t2[2]=='D'||t1[2]=='E'&&t2[2]=='F'||t1[2]=='F'&&t2[2]=='E') cout<<"11"<<endl;
					else cout<<"10"<<endl;
			  }
			  	
		}
		else cout<<"000"<<endl;
	}
	else cout<<"0000"<<endl;
	return 0;
} 
