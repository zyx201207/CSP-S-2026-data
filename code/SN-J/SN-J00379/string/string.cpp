#include<bits/stdc++.h>
using namespace std;
int pddddd(string a)
{
	int ansss=0;
	for(int i=0;i<a.size()/2;i++)
	{
		if(a[i]!=a[a.size()-i-1])
		ansss++;
	}
	return ansss;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string b="";
	cin>>n;
	while(n--)
	{
		int asd;
		char qwe;
		cin>>asd>>qwe;
		while(asd--)
		b+=qwe;
	}
	cout<<pddddd(b);
	return 0;
}
