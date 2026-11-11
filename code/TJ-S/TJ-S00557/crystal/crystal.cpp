#include<bits/stdc++.h>
using namespace std;
const int N=5e4+99;
typedef long long ll;
ll n,a[N];
ll m;
ll sum[N];
bool f1=1;
bool f2=1;
ll solve_f1()
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(sum<=m&&sum+a[i]>m)
		{
			return i;
		}
		sum+=a[i];
	}
	return n;
}

ll ans;
ll solve_f2(){
	ll d=a[2]-a[1];//¹«²î
	ll cur=0;
	if(m<d) return 1;
	
	for(int i=1;i<n;i++)//target£ºa[i+1] 
	{
		if(cur<=m&&cur+i*d>m)
		{
			return i;
		}
		cur+=i*d;
		//clog<<cur<<" ";
	}
	return n;
} 

ll solve_5000()
{
	ll cur=0;
	ll maxn=0;
	for(int i=1;i<=n;i++)
	{
		cur=0;
		for(int j=i-1;j>0;j--)
		{
			cur+=a[i]-a[j];
			if(cur<=m)
			{
				maxn=max(1ll*(i-j+1),maxn);
			}
		}
	}
	return maxn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout) ;

	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)f1=0;
		
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f2=0;
	}
	
	sort(a+1,a+n+1);
	
	if(n<=5000)
	{
		cout<<solve_5000()<<endl;
		return 0;
	}
	if(f1)
	{
		cout<<solve_f1()<<endl;
		return 0;
	}
	if(f2)
	{
		cout<<solve_f2()<<endl;
		return 0;
	}
	
	cout<<n<<endl;
	
	return 0;
}
