#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	int k=0;
	for(int i=0;i<n*2;i+=2)
	{
		int a;
		cin>>a;
		char d;
		cin>>d;
		k+=a;
		for(int j=i+1;j<=i+a;j++)
		{
			s[j]=d;
		}
	}

	int y=0;
	for(int i=0;i<k/2;i++)
	{
		if(s[i]!=s[k-i])y++;
	}
	cout<<y;
	return 0;
} 
