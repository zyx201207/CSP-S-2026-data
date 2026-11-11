#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=1,an=0,x=0,l=0;
	string s,c;
	int cn=1;
	int a[100000]={};
	char b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b;
		l+=a[i];
		for(int i=1;i<=a[i];i++)
		{
			s[cn]=b;
			cn++;
		}
	}
	int i=1;
	while(s[i]=s[l-i])
	{
		i++;
		l--;
		an++;
	}
	cout<<an;
}
