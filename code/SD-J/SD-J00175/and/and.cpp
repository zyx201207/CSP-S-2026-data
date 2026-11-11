#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=INT_MIN;
	cin>>n>>m;
	int arr[n];
	for (int i=0;i<n;i++) cin>>arr[i];
	if (m==1)
	{
		for (int i=0;i<n;i++) maxx=max(maxx,arr[i]);
		cout<<maxx;
	}
	if (m==2)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				maxx=max(maxx,arr[i]&arr[j]);
		cout<<maxx;
	}
	if (m==3)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					maxx=max(maxx,arr[i]&arr[j]&arr[a]);
		cout<<maxx;
	}
	if (m==4)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					for (int b=a+1;b<n;b++)
						maxx=max(maxx,arr[i]&arr[j]&arr[a]&arr[b]);
		cout<<maxx;
	}
	if (m==5)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					for (int b=a+1;b<n;b++)
						for (int c=b+1;c<n;c++)
							maxx=max(maxx,arr[i]&arr[j]&arr[a]&arr[b]&arr[c]);
		cout<<maxx;
	}
	if (m==5)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					for (int b=a+1;b<n;b++)
						for (int c=b+1;c<n;c++)
							for (int d=c+1;d<n;d++)
							maxx=max(maxx,arr[i]&arr[j]&arr[a]&arr[b]&arr[c]&arr[d]);
		cout<<maxx;
	}
	if (m==5)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					for (int b=a+1;b<n;b++)
						for (int c=b+1;c<n;c++)
							for (int d=c+1;d<n;d++)
								for (int e=d+1;e<n;e++)
									maxx=max(maxx,arr[i]&arr[j]&arr[a]&arr[b]&arr[c]&arr[d]&arr[e]);
		cout<<maxx;
	}
	if (m==6)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					for (int b=a+1;b<n;b++)
						for (int c=b+1;c<n;c++)
							for (int d=c+1;d<n;d++)
								for (int e=d+1;e<n;e++)
									for (int f=e+1;f<n;e++)
										maxx=max(maxx,arr[i]&arr[j]&arr[a]&arr[b]&arr[c]&arr[d]&arr[e]&arr[f]);
		cout<<maxx;
	}
	if (m==7)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					for (int b=a+1;b<n;b++)
						for (int c=b+1;c<n;c++)
							for (int d=c+1;d<n;d++)
								for (int e=d+1;e<n;e++)
									for (int f=e+1;f<n;e++)
										for (int g=f+1;g<n;g++)
											maxx=max(maxx,arr[i]&arr[j]&arr[a]&arr[b]&arr[c]&arr[d]&arr[e]&arr[f]&arr[g]);
		cout<<maxx;
	}
	if (m==8)
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int a=j+1;a<n;a++)
					for (int b=a+1;b<n;b++)
						for (int c=b+1;c<n;c++)
							for (int d=c+1;d<n;d++)
								for (int e=d+1;e<n;e++)
									for (int f=e+1;f<n;e++)
										for (int g=f+1;g<n;g++)
											for (int h=g+1;h<n;h++)
											maxx=max(maxx,arr[i]&arr[j]&arr[a]&arr[b]&arr[c]&arr[d]&arr[e]&arr[f]&arr[g]&arr[h]);
		cout<<maxx;
	}
	if (m==n)
	{
		int l=arr[0];
		for (int i=1;i<n;i++) l=l&arr[i];
		cout<<l;
	}
	return 0;
}
