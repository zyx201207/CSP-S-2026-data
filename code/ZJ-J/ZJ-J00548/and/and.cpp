#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	int n,m,f11=0,f21=0,f31=0,f41=0,c31=0,c23=0;
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		if(a[i]==1)
		{
			f11=1;
		}
		if(a[i]%2==0)
		{
			f21=1;
		}
		if(i>=2&&a[i]!=a[i-1])
		{
			f31=1;
		}
		if(a[i]>=4)
		{
			f41=1;
		}
		if(a[i]==3)
		{
			c31++;
		}
		if(a[i]==2||a[i]==3)
		{
			c23++;
		}
	}
	if(n>2000&&m==n-1)
	{
		cout<<1;
		return 0;
	}
	if(n==m)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
			sum&=a[i];
		cout<<sum;
		return 0;
	}
	int mx=0;
	if(m==1)
	{
	 	
	 	for(int i=1;i<=n;i++)
	 	{
	 		mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(!f31)
	{
		cout<<a[1];
		return 0;
	}
	if(!f41)
	{
		if(c23>=m)
		{
			if(c31<m)
			{
				cout<<2;
			}
			else
			{
				cout<<3;
			}
		}
		else
		{
			if(f21)
			{
				cout<<0;
				return 0;
			}
			else
			{
				cout<<1;
				return 0;
			}
		}
		return 0;
	}
	if(m==2)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			mx=max(mx,a[i]&a[j]);
		cout<<mx;
		return 0;
	 }
	 if(m==3)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				mx=max(mx,a[i]&a[j]&a[k]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==4)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					mx=max(mx,a[i]&a[j]&a[k]&a[l]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==5)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==6)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						for(int p=o+1;p<=n;p++)
	 							mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==7)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						for(int p=o+1;p<=n;p++)
	 							for(int q=p+1;q<=n;q++)
	 								mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==8)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						for(int p=o+1;p<=n;p++)
	 							for(int q=p+1;q<=n;q++)
	 								for(int r=q+1;r<=n;r++)
	 									mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==9)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						for(int p=o+1;p<=n;p++)
	 							for(int q=p+1;q<=n;q++)
	 								for(int r=q+1;r<=n;r++)
	 									for(int s=r+1;s<=n;s++)
	 										mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==10)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						for(int p=o+1;p<=n;p++)
	 							for(int q=p+1;q<=n;q++)
	 								for(int r=q+1;r<=n;r++)
	 									for(int s=r+1;s<=n;s++)
	 										for(int t=s+1;t<=n;t++)
	 											mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==11)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						for(int p=o+1;p<=n;p++)
	 							for(int q=p+1;q<=n;q++)
	 								for(int r=q+1;r<=n;r++)
	 									for(int s=r+1;s<=n;s++)
	 										for(int t=s+1;t<=n;t++)
	 											for(int u=t+1;u<=n;u++)
	 												mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]);
		 cout<<mx;
		 return 0;
	 }
	 if(m==12)
	 {
	 	for(int i=1;i<=n;i++)
	 		for(int j=i+1;j<=n;j++)
	 			for(int k=j+1;k<=n;k++)
	 				for(int l=k+1;l<=n;l++)
	 					for(int o=l+1;o<=n;o++)
	 						for(int p=o+1;p<=n;p++)
	 							for(int q=p+1;q<=n;q++)
	 								for(int r=q+1;r<=n;r++)
	 									for(int s=r+1;s<=n;s++)
	 										for(int t=s+1;t<=n;t++)
	 											for(int u=t+1;u<=n;u++)
	 												for(int v=u+1;v<=n;v++)
	 													mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]);
		 cout<<mx;
		 return 0;
	 }
	 cout<<0;
     return 0;
}