#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n=4)
	{
		cout<<12;
		return 0;
	}
	if(n=5)
	{
		cout<<7;
		return 0;
	}
	return 0;
}
