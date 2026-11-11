#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],b[N],c1[N],c2[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		char x;cin>>x;
		c1[i]=x-'a'+1,sum+=a[i];
	}
	int xxx=0;
	for(int i=1;i<=n;i++)
	{
		int j=n-i+1;
		b[i]=a[j],c2[i]=c1[j];
	}
	int suml=0,sumr=0,l=0,r=0,ans=0;
	int x=0;
	do
	{
		if(suml==sumr)  
		{
			suml+=a[++l],x=c1[l];
		}
		else if(sumr<suml)
		{
			sumr+=b[++r];
			if(sumr<=suml&&x!=0&&c2[r]!=x)  ans+=b[r];
			else if(sumr>suml&&x!=0&&c2[r]!=x)  ans+=suml-(sumr-b[r]),x=c2[r];
		}
		else if(suml<sumr)
		{
			suml+=a[++l];
			if(suml<=sumr&&x!=0&&c1[l]!=x)  ans+=a[l];
			else if(suml>sumr&&x!=0&&c1[l]!=x)  ans+=sumr-(suml-a[l]),x=c1[l];
		}
	}while(suml+sumr!=sum);
	cout<<ans;
}

