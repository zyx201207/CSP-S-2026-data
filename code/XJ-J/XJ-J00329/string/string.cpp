#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long sum=0;
pair<long,char> a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int j=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	int i=1;
	while(1)
	{
		if(a[i].second==a[n].second)
		{
			int r=min(a[i].first,a[n].first);
			a[i].first-=r;
			a[n].first-=r;
			if(a[i].first==0)
			{
				i++;
				j--;
			}
			if(a[n].first==0)
			{
				n--;
				j--;
			}
		}
		else{
			int r=min(a[i].first,a[n].first);
			a[i].first-=r;
			a[n].first-=r;
			sum+=r;
			if(a[i].first==0)
			{
				i++;
				j--;
			}
			if(a[n].first==0)
			{
				n--;
				j--;
			}
		}
		if(j<=0||i==n)
		{
			break;
		}
	}
    cout<<sum;
	return 0;
}