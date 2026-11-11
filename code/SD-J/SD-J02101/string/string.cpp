#include <bits/stdc++.h>
using namespace std;
int n,sum=0,size=0;
string a,b,c;
int main()
{
	freopen("D:\\SD-J02101刘孝焱\\string\\string.in\\string.in","r",stdin);
	freopen("D:\\SD-J02101刘孝焱\\string\\string.out\\string.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>b[i];
		size=size+(a[i]-'0');
	}
	for(int i=0;i<size;i++)//c数组的下标 
	{
		for(int j=0;j<n;j++)//a的下标 =b的下标 
		{
			for(int z=a[j-1];z<a[j-i]+a[j];z++) c[z]=b[j];
		}
		
	}	
	for(int i=0;i<size;i++) cout<<c[i];
	for(int i=0;i<=size/2;i++)
	{
		if(c[i]!=c[size-1-i]) sum++;
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*3
2 a
2 b
1 c*/


 
