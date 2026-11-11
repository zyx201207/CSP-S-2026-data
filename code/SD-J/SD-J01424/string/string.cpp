#include<bits/stdc++.h>//>=68
using namespace std;
const int N=200010;
int n,p=0,ans;
char a[200000010];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op;
		char asd;
		cin>>op>>asd;
		for(int j=p+1;j<=p+op;j++)
			a[j]=asd;
		p+=op;
	}
	for(int i=1;i<=p/2;i++)
		if(a[i]!=a[p-i+1])
			ans++;
	cout<<ans;
	return 0;
 } 
