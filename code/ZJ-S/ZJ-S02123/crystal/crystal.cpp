#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],s,aba,la;
bool fla=1;
bool cmp(long long a,long long b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	aba=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+1+n,cmp);
	long long t=a[2]-a[1];
	b[1]=a[1];
	b[2]=b[1]+a[2];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=t)
			fla=0;
		if(a[i]-a[i-1]>m){aba=min(max(i-la,n-i),aba);la=i;}
		b[i]=b[i-1]+a[i];
//		if(fla==0)break;
	}
	if(fla==1){
		for(int i=1;i<=n;i++)
		{
			if(t*((1+i)*i/2)>m)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}else
	{
		for(int i=aba;i>1;i--)
		{
			for(int j=1;j<=aba-i+1;j++)
			{
				long long s=0;
				//s=b[j+i-2]-b[j];
				//s-=i*a[j];
				//s+=a[j]*2;
				s=(i-1)*a[j+i-1]-b[j+i-2]+b[j-1];
				//for(int k=j;k<j+i;k++){s+=a[j+i-1]-a[k];if(s>m)break;}
				//i-2::s=i-2(a[j+i-1])-a[j]~a[j+i-2])
				if(s<=m){
					cout<<i<<endl;
					return 0;
				}
			
		}
	}
	cout<<0<<endl;
	}
	return 0;
}/*
			3
            2 23 25 45 46 47 75
            TLE
*/


