#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1; 
vector<long long>a,b;
bool A=true,B=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long mid;
		cin>>mid;
		a.push_back(mid);
		b.push_back(mid);
		if(a[i]!=i)A=false;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int deltad=1;
	for(int i=1;i<=n;i++)
	{
		if(i>2)
		{
			int d1=a[i-1]+a[i-2];
			int d2=a[i]-a[i-1];
			if(d1!=d2)B=false;
		} 
	}
	if(B||A)
	{
		cnt=ceil(m*1.00/deltad*1.00);
		cout<<cnt<<endl;
		return 0;
	}
	int half=floor((int)a.size()/2);
	int i=half;
	long long middle=a.at(half);
	while(m>0)
	{
		long long delta=abs(middle-a.at(i));
		if((m-delta)<0)break;
		m-=delta;
		a[i]+=abs(delta);
		i--;
		if(m>0&&i<0)
		{
			half=floor((half+n)/2);
			i=half;
			middle=a.at(half);
		}
	}
	while(half+1<n&&a[half+1]==a[half])half++;
	int start=a.at(half);
	for(int i=half-1;i>=0;i--)
	{
		if(a[i]==start)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

