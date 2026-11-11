#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in.txt","r",stdin);	
	//freopen("string.out.txt","w",stdout);
	int a,h=0,ac=0;
	string s;
	cin>>a;
	for(int i=0;i<a;i++)
	{
	
		int b;
		string c;
		cin>>b>>c;
		h+=b;
		for(int i=0;i<b;i++)
		{
			s+=c;
		}
	}
	for(int i=0;i<h/2;i++)
	{
		if(s[i]!=s[h-i-1]) 
		{
			ac+=1;
		
			
		}
	}
	cout<<ac;
}
