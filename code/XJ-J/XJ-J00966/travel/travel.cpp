#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	
	char s,ss;
	s=s1[2];
	ss=s2[2];
	
	string a,b;
	a+=s1[0];
	a+=s1[1];
	b+=s2[0];
	b+=s2[1];
	
	
	if(a==b) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	
	if(s=='A'||s=='B'||s=='C')
	{
		if(ss=='A'||ss=='B'||ss=='C') cout<<1;
		else{
			cout<<0<<0;
			return 0;
		}
		
	 } 
	 if(s=='D'||s=='F')
	 {
	 	if(ss=='D'||ss=='F') cout<<1;
		else{
			cout<<0<<0;
			return 0;
		}
	 }
	
	
	
	
	
	if(s=='A')
	{
		if(ss=='B') cout<<1;
		else cout<<0;
	}
		
	if(s=='B')
	{
		if(ss=='A'||ss=='C') cout<<1;
		else cout<<0;
	}
	
	if(s=='C')
	{
		if(ss=='B') cout<<1;
		else cout<<0;
	}
	
	if(s=='D')
	{
		if(ss=='F') cout<<1;
		else cout<<0;
	}
	
	if(s=='F')
	{
		if(ss=='D') cout<<1;
		else cout<<0;
	}
	return 0;
}

