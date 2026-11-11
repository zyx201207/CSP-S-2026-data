#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,s=0,h;
	string a[100005],c[10000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		h+=x;
		cin>>c[i];
		for(int j=1;j<=x;j++)
		{
			a[i]=c[i];
		}
	}
	for(int i=1;i<=h/2;i++)
	{
		if(a[i]!=a[h])
		{
			s++;
		}
		h--;
	}
	cout<<s;
	return 0;
}
