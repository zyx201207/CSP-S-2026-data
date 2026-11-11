#include<bits/stdc++.h>
using namespace std;
int k,n;
bool a[10];
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int f=1;
	for(int i=0;i<c1.size();i++)
	{
		if(c1[i]!=c2[i]){f=0;break;}
	}
	if(f==0){cout<<"0000";return 0;}
	cout<<f;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i]){a[i]=0;}
		else a[i]=1;
	}
	if(a[0]==0||a[1]==0){cout<<"000";return 0;}
	cout<<1;
	if((s1[2]<='C'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]>='D')){cout<<"00";return 0;}
	cout<<1;
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){cout<<1;}
	else{cout<<0;}
	return 0;
}

