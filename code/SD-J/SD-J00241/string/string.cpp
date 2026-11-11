#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct{
	long long shu;
	char mu;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long num=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].shu>>a[i].mu;
		num+=a[i].shu;
	}
	long long midl,midr;
	if(num%2==0) 
	{
		midl=num/2;
		midr=midl+1;
	}
	else
	{
		midl=num/2+1;
		midr=num/2+1;
	}
	int l=1,r=n;
	char mul=a[1].mu,mur=a[n].mu;
	long long shul=min(a[1].shu,midl),shur=min(a[n].shu,midr),chong=0;
	long long cnt=min(shul,shur);
	while(shul<=midl&&shur<=midr) 
	{
		if(mul==mur) chong+=cnt;
		if(shul<shur)
		{
			long long cmp=shul;
			shul=min(shul+a[++l].shu,midl);
			mul=a[l].mu;
			cnt=min(shul,shur)-cmp;
		}
		else if(shul>shur)
		{
			long long cmp=shur;
			shur=min(shur+a[--r].shu,midr);
			mur=a[r].mu;
			cnt=min(shul,shur)-cmp;
		}
		else
		{
			if(r==l+1||r==l) break;
			else 
			{
				long long cmp=shul;
				shul=min(shul+a[++l].shu,midl);
				shur=min(shur+a[--r].shu,midr);
				mul=a[l].mu;
				mur=a[r].mu;
				cnt=min(shul,shur)-cmp;
			}
		}
	}
	cout<<midl-chong;
	return 0;
}
