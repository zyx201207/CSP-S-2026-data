#include<bits/stdc++.h>
using namespace std;
const int N=1.6e6+10;
char a[N];
long long b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	if(n==1) cout<<0;
	else if(n==2) 
		{
			int a1,a2;
			char c1,c2;
			cin>>a1>>c1>>a2>>c2;
			if(c1==c2) cout<<0;
			if(a1+a2==2&&a1+a2==4)
			{
				if(a1==2)cout<<2;
				else cout<<1;
			}
			else cout<<min(a1,a2);
		}
	else
	{
		for(int i=0;i<n*2;i+=2)
		{
			int val;
			char c;
			cin>>val>>c;
			a[i]=c;
			b[i]=val;
		}
		for(int i=8*n-3;i>=0;i-=8) if(a[i]==a[i+8]){a[i]+=a[i+8];a[i+8]=0;}
		int r=8*n;
		for(int i=0;i<n;i++)
		{
			if(b[i]==0)  ;
			else
			{
			for(int j=r-1;;j--) if(b[j]!=0) {r=j;break;}
			if(b[i]>b[r]){b[i+1]=b[i]-b[r];b[i]=b[r];a[i+1]=a[i];}
			if(b[i]<b[r]){b[r+1]=b[i];b[r]-=b[i];a[r+1]=a[r];r++;}
			}
		}
		r=8*n;
		for(int i=0;i<n;i++)
		{
			if(b[i]==0) goto c;
			for(int j=r-1;;j--) if(b[j]!=0) {r=j;break;}
			if(a[i]!=a[r]) cnt+=b[i];
			c: ;
		}
		cout<<cnt;
	}
	return 0;
}

