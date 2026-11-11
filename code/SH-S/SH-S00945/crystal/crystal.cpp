#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.i","r",stdin);
	freopen("crystal.i","w",stdout);
	long long n;//数量 
	long long m;// 最多操作次数 
	int b=1;//[]里面的数 
	int x=1;// 最多水晶数 
	int c;//输入的数 
	int a[10005];//数组 
	int d=-1;//[]里面的数 
	int e=-1; 
	int f=0;
	int g=-1;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>c;
		c=a[b];
		b++;
	}
	
	for(int i=1;i<m;i++)
	{
		d++;
		e++;
		f++;
		g++;
		if(a[d]+e==a[d+f]||a[d]==a[d+f]+e)//1 2,3 4
		{
			x++;
		}
		if(a[d+f+g]+e==a[d+f]||a[d]==a[d+f+g]+e)//1 3,2 4
		{
			x++;
		}
		
	}
	
	cout<<x;
	return 0;

}
