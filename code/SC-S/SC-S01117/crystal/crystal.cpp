 #include<bits/stdc++.h>
using namespace std;
vector <int> arr;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,max1=1,maxs,maxi,m1,s,ans=1,num,cun;
	cin>>n>>m;
	m1=m;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		arr.push_back(num);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		if(arr[i]==arr[i+1])
		{
			max1++;
		}
		else
		{
			if(max1>cun)
			{
				cun=max1;
				maxs=arr[i];
			}
		}
		max1=1;
	}
	ans=cun+ans;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==maxs)
		{
			maxi=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==arr[maxi])
		{
			ans++;
		}
	}
	for(int i=1;i<m;i++)
	{
		if(m1==0)
		{
			break;
		}
		s=arr[maxi-i];
		if(s>m1)
		{
			break;
		}
		m1=m1-s;
		ans++;
	}
	cout<<ans;
	return 0;
}