#include<bits/stdc++.h>
using namespace std;
string r,x,rs,xs;
bool f1,f2,f3,f4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rs>>x>>xs;
	f1=(r==x? 1:0);
	if(rs[0]==xs[0]&&rs[1]==xs[1]&&f1)  f2=1;
	else f2=0;
	int s1=rs[2]-'A'+1,s2=xs[2]-'A'+1;
	if(f2&&(s1<=3&&s2<=3)||(s1>3&&s2>3))  f3=1;
	else f3=0;
	s1=(s1>5? s1:5),s2=(s2>5? s2:5);
	if(f3==1&&abs(s1-s2)==1)  f4=1;
	else  f4=0;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}