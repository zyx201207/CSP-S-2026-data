#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	int a=(a2[0]-'0')*10+a2[1]-'0';
	int b=(b2[0]-'0')*10+b2[1]-'0';
	if(a==b) cout<<1;
	else
	{
		cout<<"000\n";
		return 0;
	}
	int s1=a2[2]-'A',s2=b2[2]-'A';
	if((s1<3 && s2<3)||(s1>=3 && s2>=3)) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(s1-s2)==1) cout<<"1";
	else cout<<"0";
	return 0;
}
