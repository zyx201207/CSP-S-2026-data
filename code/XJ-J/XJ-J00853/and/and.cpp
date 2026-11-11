#include<bits/stdc++.h>
using namespace std;
long long int i,n,a[1000055],b,m,k;
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n;
	for(i=1;i<=n;i++)
	{
    cin>>m;
	while(m!=0)
	{
		a[++k]=m%2;
		m/=2;
		a[k+1]="aa ";
	}
    }

    
	for(i=k;i>=1;i--)
	cout<<a[i];
}