#include<bits/stdc++.h>
using namespace std;
int n,k=INT_MIN,ma;
long long m,a[500010],d[500010],mi;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long s=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=s){
			f=0;
			break;
		}
	}
	sort(a+1,a+1+n);
	if(f){
		k=1;
		int l=n-1;
		mi=m;
		while(mi>0&&l>0)
		{
			if(mi>=(a[n]-a[l]))
			{
				k++;
				mi-=a[n]-a[l];
				l--;
			}
			else break;
		}
		if(k==1)cout<<0;
		else cout<<k;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		mi=m;
		k=1;
		int l=i-1;
		while(mi>0&&l>0)
		{
			if(mi>=(a[i]-a[l]))
			{
				k++;
				mi-=a[i]-a[l];
				l--;
			}
			else break;
		}
		ma=max(ma,k);
	}
	if(ma==1)cout<<0;
	else cout<<ma;
	return 0;
} 
