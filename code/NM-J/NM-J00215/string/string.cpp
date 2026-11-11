#include<cstring>
#include<iostream>
using namespace std;
int a[100];
char b[100],c[100],d[100],e[100];
string s;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
		for(int j=0;j<a[i];j++)
        {
            c[j]=b[i];
            d[s]=c[j];
            s++;
        }
	}
	int m=0,p=s;
	while(p!=0)
	{
		e[m]=d[p-1];
		m++;
		p--;
	}
	int z=0;
	for(int i=0;i<s;i++)
	{
		cout<<d[i];
		if(e[i]!=d[i])
		{
			z++;
		}
	}
	cout<<z/2;
	return 0;
}
