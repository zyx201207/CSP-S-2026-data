#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int d[N];
int n,m;
int ans;
int check(int x)
{
//	cout<<"PPP"<<x<<endl;
	
	ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x) 
		{
			continue;
		}
		else if(a[i]==x) d[i]=0;
		else d[i]=x-a[i];
		cnt++;
	}
	sort(d+1,d+cnt+1);
	//if(x==2) cout<<'p'<<endl;
//	if(x==2)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			cout<<d[i]<<" ";
//		}
//		cout<<endl;
//	}
	int mm=m;
	for(int i=1;i<=cnt;i++)
	{
//		if(x==2)
//		{
//			cout<<mm<<" "<<mm-d[i];
//		}
		
		if(mm>=d[i])
		{
			mm-=d[i];
			ans++;
		}
		else break;
	}
	//cout<<endl<<endl<<"PPPP   "<<ans<<endl;
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//system("fc a.ans a.out"); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sti=clock();
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=a[1];
	int r=a[n];
	int fans=0;
	while(r-l>80)
	{
	//	cout<<l<<" "<<r<<endl;
		int mid=(r-l)/3;
		int mid1=l+mid;
		int mid2=r-mid;
	//	cout<<mid1<<endl;cout<<mid2<<endl;
		int Q=check(mid1);
		int P=check(mid2);
		if(Q>P)
		{
			fans=max(fans,Q);
			r=mid2;
		}
		else 
		{
			fans=max(fans,P);
			l=mid1;
		}
		
		
	}
	//cout<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++)
	{
		fans=max(fans,check(i));
	//	if(check(i)==3845) cout<<"PP"<<i<<endl;
	}
	cout<<fans<<endl;
	//cerr<<1.0*(clock()-sti)/CLOCKS_PER_SEC<<'\n';
	return 0;
 } 
 /*
 
 5 5
 1 2 4 8 9
 
 5 8
 -3 -1 2 2 7
 */
