#include <bits\stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin >> a >> b;
	int na[a];
	int nb[b];
	for(int i0=1;i0<a;i0++)
	{
		cin >> na[i0];
	}
	int ma;
	for(int i1=0;i1<a-1;i1++)
	{
		int z=na[i1];
		na[i1]=0;
		for(int i2=0;i2<a-1;i2++)
		{
			ma=max((na[i1] & na[i2]) , (na[i1+1] & na[i2+1]));
		}
		na[i1]=z;
	}
	for(int i1=0;i1<a-1;i1++)
	{
		int z=na[i1];
		na[i1]=0;
		for(int i2=0;i2<a;i2++)
		{
			if((na[i1] & na[i2])==ma)
			{
				na[i1]=na[i2]=0;
				break;
			}
		}
		na[i1]=z;
	}
	
	
	
	for(int i=0;i<b-2;i++)
	{
		int mm=ma;
		for(int i1=0;i1<a-1;i1++)
		{
			int mma=0;
			int z=na[i1];
			na[i1]=0;
			for(int i2=0;i2<a;i2++)
			{
				mma=max(mma , (ma & na[i2+1]));
			}
			na[i1]=z;
			ma=mma;
			}
		for(int i1=0;i1<a;i1++)
		{
			if((na[i1] & mm)==ma)
			{
				na[i1]=0;
				break;
			}
		}
	}
	
	
	
	/*int mma=0;
	for(int i=0;i<b-2;i++)
	{
		for(int i1=0;i1<a-1;i1++)
		{
			int z=na[i1];
			na[i1]=0;
			for(int i2=0;i2<a;i2++)
			{
				mma=max(mma , (ma & na[i2]));
			}
			na[i1]=z;
			ma=mma;
			mma=0;
		}
	
	}*/
	/*int mma;
	for(int q=1;q<b;q++)
	{
		int z=na[q];
		na[q]=0;
		for(int i2=0;i2<a-1;i2++)
		mma=max((ma & na[i2]) , (ma & na[i2+1]));
		na[q]=z;
		ma=mma;
	}*/
	
	/*for(int i=0;i<b;i++)
	{
		for(int ii=0;ii<a-1;ii++)
		{
			nb[i]=max(na[ii],na[ii+1]);
		}
		for(int iii=0;iii<a;iii++)
			{
				if(na[iii]==nb[i])
				{
					na[iii]=0;
				}
			}
	}
	int ma=nb[0]&nb[1];
	for(int i=2;i<b;i++)
	{
		ma=(ma & nb[i]);
	}*/
	cout << ma;
	return 0;
}
