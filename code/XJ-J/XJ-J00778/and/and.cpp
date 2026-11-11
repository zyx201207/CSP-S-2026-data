#include<bits/stdc++.h>
using namespace std;

int a[200001];
string s[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
for(int i=1;i<=n;i++)
{  
   for(int j=1;j<=n;j++)
   {
   	if(a[j]<a[j+1])
	{
		int ddd=a[j];
		a[j]=a[j+1];
		a[j+1]=ddd;
	}
   }	
}
int sum=a[1];
for(int i=2;i<=m;i++){
    sum&=a[i];
}
	cout<<sum;
	return 0;
}