#include<iostream>
using namespace std;
char zu[1000000000];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	string aaa;
	int n,x=0,h=0;
	cin>>n;
	
	while(n--)
	{
		int a;
		char b;
		cin>>a>>b;
		for(int i=0;i<a;i++)
		{
			zu[x]=b;
			x++;
		}
	}
	for(int i=x-1,j=0;i>=0;i--,j++)
	{
		if(zu[i] != zu[j])
		{
				h++;
		}
	}
	cout<<h/2;
	return 0;
}
