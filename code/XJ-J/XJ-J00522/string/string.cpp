#include<bits/stdc++.h>
using namespace std;

int main()
{
    preopen(string.in,'w',stdin);
	preopen(string.out,'r',stdout);
	int n,a1,c1,R,L,ans=0,num=0;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a1>>c1;
		for(int i=1;i<=a1;i++)
		{
			a[i]+=c1;
			ans++;
		}
	}
	R=ans;
	L=1;
	while(R>L)
    {
    	if(a[L]-a[R]!=0)
    	{
    		num++;
		}
		R--;
		L++;
	}
	cout<<num;
	return 0;
}