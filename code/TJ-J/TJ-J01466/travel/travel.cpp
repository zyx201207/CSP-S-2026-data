#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string r1,s1,x1,s2;
	cin>>r1>>s1>>x1>>s2;
	int ans=0;
	if(r1!=x1)
	{
		cout<<0<<0<<0<<0;	
		return 0;
	}
	else cout<<1;
	if(s1[1]!=s2[1])
	{
		cout<<0;
	}
	else if(s1[0]==s2[0])
	{
		cout<<1;
		ans=1;
	}
	else{
		cout<<0;
	}
	if(ans==1)
	{
		if(s1[2]==s2[2])
		{
			cout<<1;
			ans=1;
		}
		else if(s1[2]=='C'&&s2[2]=='D'){
			cout<<0;
			ans=0;
		}
		else if(s1[2]=='D'&&s2[2]=='C'){
			cout<<0;
			ans=0;
		}
		else if(s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')
		{
			cout<<1;
			ans=1;
		}
		
	}
	else{
		cout<<0;
		ans=0;
	}
	if(ans==0)
	{
		cout<<0;
		return 0;
	}
	else if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
