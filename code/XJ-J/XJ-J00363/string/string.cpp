#include<bits/stdc++.h>//已经给好了顺序，不用改 
using namespace std;
long long int n,ans,l=0,r=0;//l，r标记两边差几个才对称 
struct node
{
	long long int a;//串长 
	char b;//字母 
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int i,j,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	
	for(i=1;i<=n/2;i++)
	{
		if(a[i].b==a[n-i+1].b&&a[i+1].b==a[n-i].b&&a[i].b==a[i+1].b)//两侧字符相同且内侧字符四者都相同,ok 
		{
			ans+=0;
			if(a[i].a+l<a[n-i+1].a+r)
	          r=a[n-i+1].a+r-l-a[i].a,l=0;
	        else
	          if(a[i].a+l>a[n-i+1].a+r)
	            l=a[i].a+l-r-a[n-i+1].a,r=0;
	        else
	          l=r=0;
		}
		else
		  if(a[i].b==a[n-i+1].b&&a[i].b!=a[i+1].b)//两侧字符相同但内侧字符不相同,ok
		    {
		    	ans+=0;
		    	if(a[i].a+l<a[n-i+1].a+r)
	              r=a[n-i+1].a+r-l-a[i].a,l=0;
	            else
	              if(a[i].a+l>a[n-i+1].a+r)
	                l=a[i].a+l-r-a[n-i+1].a,r=0;
	            else
	              l=r=0;
			}
		else
		  if(a[i].b!=a[n-i+1].b&&(n-i+1)-i>1)//两侧字符不同且不在中间 
		    {
		    	ans+=min(a[i].a,a[n-i+1].a);
		    	if(a[i].a+l<a[n-i+1].a+r)
	              r=a[n-i+1].a+r-l-a[i].a,l=0;
	            else
	              if(a[i].a+l>a[n-i+1].a+r)
	                l=a[i].a+l-r-a[n-i+1].a,r=0;
	            else
	              l=r=0;
			}
		
		else
		  if(a[i].b!=a[n-i+1].b&&(n-i+1)-i<=1) // 两侧字符不相同且在中间
		  {
		  	ans+=min(a[i].a,a[n-i+1].a);
	        l=r=0;
		  }
		cout<<l<<' '<<r<<' '<<ans<<endl;
	}
	ans+=max(l,r);
	cout<<ans;
	return 0;
} 
/*
目前相同的字符串可以处理，差不同的字符串处理 
ans有待处理



6
10 a
4 a
4 c
2 d
6 a
8 b

10 
*/
