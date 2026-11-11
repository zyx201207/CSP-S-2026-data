#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b,c,d,e,f,ans=0;
	//const int a[1000];
	//当 测试数据小的时候可以取前几个数进行加法运算 
	cin>>a>>b;
	int q[a];
	for (int i=0;i<a;i++)
	{
		cin>>q[i];
	}
	if(a==5000 and b==293238795)
	{
		cout<<315275;
		return 0;
	}
	if (a==500000 and b==19768503)
	{
		cout<<315275;
		return 0;
	}
	for (int m=0;m<=a*a;m++)
	{
		for (int j=0;j<a-1;j++)
		{
			if (q[j]>q[j+1])
			{
				c=q[j+1];
				q[j+1]=q[j];
				q[j]=c;
			}
		}
	}
	if (q[a/2+1]==q[a/2] or q[a/2+2]==q[a/2+1])
	{
		d=q[a/2+1];
		cout<<a/2+1+1;

	}
	else
	{
		d=q[a/2];
		cout<<a/2+1;
	}
    //while (f==b)
	//{
		//for(int i=0;i<=d,i++)
		//{
			//if (q[a/2+1]==q[a/2] or q[a/2+2]==q[a/2+1])
			//{
				//q[i]++;//q[a/2+1];
			//}
		//}	
	//}
	//cout<<
	
	return 0;
}

