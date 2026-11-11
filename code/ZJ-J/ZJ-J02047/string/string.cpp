#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	int a[200010]={0},b[200010]={0};//a len,b letter
	int cnt=0;
	scanf("%d",&n);
	long long len=0;
	for(int i=1;i<=n;i++)
	{
		long long x;
		scanf("%lld",&x);
		cnt++;
		char c;
		cin>>c;
		a[cnt]=x;
		b[cnt]=c-'a'+1;
		len+=x;
	}
	long long h=len/2;//yigongxci
	int l=1,r=n;//zuoyouzhizhen
	long long t=0;//answer
//	for(int i=1;i<=n;i++)
//	cout<<a[i]<<" "<<b[i]<<endl;
	while(l<r)
	{
//		cout<<l<<" "<<r<<endl;
		if(b[l]!=b[r])t+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];a[r]=0;r--;
		}
		else if(a[r]>a[l]){
			a[r]-=a[l];a[l]=0;l++;
		}
		else r--,l++;
	}
	cout<<t;
	
	
	

//	int a_left[200010]={0},b_left[200010]={0};
//	int a_right[200010]={0},b_right[200010]={0};
//	int ll=0;
//	int lr=0;
//	int l_o=0,r_o=0;
//	int l_o_l=0,r_o_l=0;
//	int p=0;int d;//d biaoji
//	for(int i=1;i<=n;i++)
//	{
//		p+=a[i];
//		if(p>=h) d=i;
//	}
//	if(h%2==1)
//	{
//		ll=d-1;
//		lr=n-d;
//		for(int i=1;i<=d-1;i++)
//			a_left[i]=a[i],b_left[i]=b[i];
//		if(a[d]/2!=0)
//			a_left[d]=a[d]/2,b_left[d]=b[d],ll++,a_right[1]=a[d]/2,b_right[1]=b[d],lr++;
//	}
//	if(h%2==0)
//	{
//		ll=d-1;
//		lr=n-d;
//		for(int i=1;i<=d-1;i++)
//			a_left[i]=a[i],b_left[i]=b[i];
//		if(a[d]/2!=0)
//			a_left[d]=a[d]/2,b_left[d]=b[d],ll++,a_right[1]=a[d]/2,b_right[1]=b[d],lr++;
//	}
	return 0;
}
