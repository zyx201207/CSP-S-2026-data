#include<bits/stdc++.h>
using namespace std;
string s[20000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,q=0,t=0;
	string c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			s[q]=c;
			q++;
		}
	}
	int l=0,r=q-1;
	while(l<r)
	{
		if(s[l]!=s[r])
			t++;
		l++;
		r--;
	}
	cout<<t;
	return 0;
 } 
