#include<bits/stdc++.h>//T1ok1
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c1,c2;
	int num1,num2;
	char s1,s2;
	cin>>c1>>num1>>s1>>c2>>num2>>s2;
	if(c1==c2)cout<<"1";
	else 
	{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if(num1==num2)cout<<"1";
	else 
	{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')||(s1!='F'&&s1!='D'&&s2!='F'&&s2!='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if((s1=='C'&&s2=='A')||(s1=='A'&&s2=='C'))cout<<"0";
	else cout<<"1";
	return 0;
}
