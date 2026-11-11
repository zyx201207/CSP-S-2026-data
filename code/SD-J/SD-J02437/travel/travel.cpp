#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>s1>>b>>s2;
	if(a==b)
	{
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<"1";
			if(s1[3]!='C' && s2[3]!='D' )
				cout<<"00";
			else
			{
				cout<<"1";
				int x=s1[3]-'0',y=s2[3]-'0';
				if(x-y==0 || y-x==0)
					cout<<"1";
				else
					cout<<"0";
			}
		}else{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
} 
