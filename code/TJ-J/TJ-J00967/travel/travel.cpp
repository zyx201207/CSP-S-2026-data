#include<bits/stdc++.h>
using namespace std;
int ans1=0,ans2=0,ans3=0,ans4=0;
int c1,c2,r1=0,r2=0,gd1,gd2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2) ans1=1;
	r1=(s1[0]-'0')*10+(s1[1]-'0');
	r2=(s2[0]-'0')*10+(s2[1]-'0');
	if(r1==r2&&ans1==1) ans2=1;
	gd1=s1[2]-'A';
	gd2=s2[2]-'A';
	if((gd1>2&&gd2>2||gd1<=2&&gd2<=2)&&ans2==1&&ans1==1) ans3=1;
	if((s1[2]-'A'==(s2[2]-'A')+1||s1[2]-'A'==(s2[2]-'A')-1)&&ans3==1&&ans2==1&&ans1==1) ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
