#include <bits/stdc++.h>
using namespace std;
//开long long!!!!!! 
//目前这个代码复杂度是不可能通过后50数据的！先放着，回来再看，如果A不出正确答案，那就去把特殊性质AB搞掉，还能多拿30分！ 
const int maxn=500010;
long long a[maxn];
long long cha[maxn];
long long n,m,ans,sum,m1; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		cha[i]=a[i+1]-a[i];
	}
	long long ge;
	for(int k=1;k<n;k++)
	{
		sum=0;
		ge=1,m=m1;
		int i;
		for(i=k;i<n;i++)
	    {
	    	if(m>=cha[i])
	    	{
	    		sum+=1;
	    		if(cha[i]) m-=ge;
	    		cha[i+1]=cha[i+1]*(++ge);
	    	}
	    	else break;
	    }
	    //cout<<sum<<" ";
	    ans=max(sum,ans);
	    if(i==n-1) break;
	}
	cout<<ans+1<<endl;//真正的计数器，需要sum吗？ 
	return 0;
} 
