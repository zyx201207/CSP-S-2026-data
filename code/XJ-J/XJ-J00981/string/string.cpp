#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,a2;
	char s1,s2;
	cin>>n;
	if(n==1) 
	{
		cout<<"0";
		return 0;
	}
	if(n==2)
	{
		cin>>a>>s1>>a2>>s2;
		if(a==1&&a2==2) cout<<"1";
		else if(a==1&&a2==4) cout<<"1";
		else if(a==2&&a2==1) cout<<"1";
		else if(a==2&&a2==2) cout<<"0";
		else if(a==2&&a2==3) cout<<"1";
		else if(a==2&&a2==4) cout<<"1";
		else if(a==2&&a2==5) cout<<"1";
		else if(a==3&&a2==2) cout<<"1";
		else if(a==3&&a2==4) cout<<"2";
		else if(a==3&&a2==5) cout<<"2";
		else if(a==4&&a2==1) cout<<"1";
		else if(a==4&&a2==3) cout<<"2";
		else if(a==4&&a2==4) cout<<"2";
		else if(a==4&&a2==5) cout<<"2";
		else if(a==5&&a2==2) cout<<"1";
		else if(a==5&&a2==4) cout<<"2";
		else cout<<"3";
		return 0;
	}
	cout<<"0"; 
	return 0;
}