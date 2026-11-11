#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m,cnt=0;
	cin>>m;
	string s1;
	int p[m],len=0;
	char q[m];
	for(int a=0;a<m;a++)
	{
		cin>>p[a]>>q[a];
		len+=p[a];
	}
	for(int a=0;a<m;a++)
	{
		for(int b=0;b<p[a];b++)
		{
			s1+=q[a];
		}
	}
	for(int a=0;a<(len/2);a++)
	{
		if(s1[a]!=s1[len-a-1])
		{
			s1[len-a-1]=s1[a];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}