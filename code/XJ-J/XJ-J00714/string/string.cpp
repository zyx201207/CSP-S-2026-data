#include<bits/stdc++.h>
using namespace std;
long long int n,x,y,m,i,j,k=0,s;
string w;char a;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>s>>a;
		j+=s;
		for(i=1;i<=s;i++)
		{
			k++;
			w[k]=a;
		}
	}
	i=1;
	while(i<=j)
	{
		if(w[i]==w[j])
		{
			i++;j--;
		}
		else
		{
			i++;
			j--;
	     	m++;
		}
	}
	cout<<m;
}