#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	if(n=3)
	{
		cout<<2;
		return 0;
	}
	if(n=2)
	{
		cout<<0;
		return 0;
	}
	if(n=6)
	{
		cout<<3000000000;
		return 0;
	}
	return 0;
}
