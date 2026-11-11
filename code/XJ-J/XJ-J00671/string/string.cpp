#include<bits/stdc++.h>
using namespace std;
long long  int a,i,j=1,s,t,k,l,f,ans=1,b,z,m=1;
char n[200005];
char X[2000005];
char h;
int main()
{
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	cin>>a;
	for(i=1;i<=a;i++)
	{
		cin>>b>>h;
		j+=b;
		n[i]=h;
           for(z=ans;z<=j;z++)
			{
				X[z]=h;
			}
				ans+=b;
	}
	for(i=1;i<=a-1;i++)
	{
		if(n[i]==n[i+1])
		m++;
	}
	if(m==a)
	{
		cout<<0;
		return 0;
	}
	k=ans;
	for(i=1;i<=ans;i++)
	{
		if(X[i]!=X[ans-k]&&i<k)
		{
			t++;
		}
		k--;
	}
	cout<<t;
	fclose(stdin);
		fclose(stdout);
		return 0;
    }   