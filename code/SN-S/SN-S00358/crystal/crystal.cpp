#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500010;

int n, m, cnt=1, b=1, yans1, yans2, ls;
int a[N];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++)	cin>>a[i];

	sort(a+1, a+n+1);
	
	
	int cnt=0;
	int k=a[2]-a[1];
	
	for(int i=1; i<=n; i++)
	{
		ls=i*k;
		if(cnt+ls>m)
		{
			cout<<i<<endl;
			return 0;
		}
		else if(cnt+ls<=m)
		{
			cnt+=ls;
		}
	}
	cout<<n<<"\n";
//	for(int i=1; i<=m/k; i++){
//		if(cnt+i>m/k){
//			cout<<i;
//			return 0;
//		}
//		else cnt+=i;
//	} 
//	cout<<n;
	return 0;
}
//pat:::::int->long long
//pat:::::freopen½â×¢ÊÍ
//pat::::: 
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//
//const int N=500010;
//
//int n, m, cnt=1;
//int a[N];
//
//signed main()
//{
//	//freopen("crystal.in", "r", stdin);
//	//freopen("crystal.out", "w", stdout);
//	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin>>n>>m;
//	for(int i=1; i<=n; i++)	cin>>a[i];
//
//	sort(a+1, a+n+1);
//	
//	for(int i=1; i<=n; i++) a[i]+=a[i-1];
//	
//	int l=1, r=n;
//	
//	while(l<=r)
//	{
//		int qjh=a[r]-a[l-1];
//		//int mid=(l+r)/2;
//		
//		if(qjh+m==(r-l+1)*(a[r]-a[r-1]))
//		{
//			cout<<1;
//			cout<<r-l+1<<"\n";
//			return 0;
//		}
//		
//		if(qjh+m<(r-l+1)*(a[r]-a[r-1])&&cnt==0)
//		{
//			l++;
//			qjh=a[r]-a[l-1];
//			cout<<2<<' '<<l<<' '<<r<<' '<<qjh<<endl; 
//			for(int i=m; i>=0; i--)
//			{
//				if((qjh+i)==(r-l+1)*(a[r]-a[r-1]))
//				{
//					cout<<qjh<<' '<<i<<' '<<a[r]-a[r-1]<<endl;
//					cout<<r-l+1<<"\n";
//					return 0;
//				}
//			}
//			cnt=1;
//		} //qjh+m>(r-l+1)*(a[r]-a[r-1])
//		else
//		{
//			r--;
//			for(int i=m; i>=0; i--)
//			{
//				if((qjh+i)==(r-l+1)*(a[r]-a[r-1]))
//				{
//					cout<<r-l+1<<"\n";
//					return 0;
//				}
//			}
//			cnt=0;
//		}
//	}
//	return 0;
//}
////pat:::::int->long long
////pat:::::freopen½â×¢ÊÍ
////pat:::::
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//
//const int N=500010;
//
//int n, m, cnt=1, b=1, yans1, yans2;
//int a[N];
//
//signed main()
//{
//	//freopen("crystal.in", "r", stdin);
//	//freopen("crystal.out", "w", stdout);
//	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cin>>n>>m;
//	for(int i=1; i<=n; i++)	cin>>a[i];
//
//	sort(a+1, a+n+1);
//	
//	for(int i=1; i<=n; i++) a[i]+=a[i-1];
//	
//	int l=1, r=n;
//	
//	while(l<=r)
//	{
//		int qjh=a[r]-a[l-1];
//		//int mid=(l+r)/2;
//		
//		if(qjh+m==(r-l+1)*(a[r]-a[r-1]))
//		{
//		//	cout<<1;
//			cout<<r-l+1<<"\n";
//			return 0;
//		}
//		
//		l++;
//		qjh=a[r]-a[l-1];
//		//cout<<2<<' '<<l<<' '<<r<<' '<<qjh<<endl; 
//		for(int i=m; i>=0; i--)
//		{
//			if((qjh+i)==(r-l+1)*(a[r]-a[r-1]))
//			{
//				//cout<<qjh<<' '<<i<<' '<<a[r]-a[r-1]<<endl;
//				yans1=r-l+1;
//			}
//		}
//		l--;
//					
//	
//		r--;
//		qjh=a[r]-a[l-1];
//		//cout<<3<<' '<<l<<' '<<r<<' '<<qjh<<endl; 
//		for(int i=m; i>=0; i--)
//		{
//			if((qjh+i)==(r-l+1)*(a[r]-a[r-1]))
//			{
//				//cout<<qjh<<' '<<i<<' '<<a[r]-a[r-1]<<endl;
//				yans2=r-l+1;
//			}
//		}
//		r++;
//		
//		if(yans1>=yans2&&yans1!=0){
//			cout<<yans1<<"\n";
//			return 0;
//		}	
//		
//		else if(yans1<yans2){
//			cout<<yans2;
//			return 0;
//		} 
//		
//		if(b=1){
//			l++;
//			b=2;
//		}
//		else if(b=2){
//			r--;
//			b=1;
//		}
//	}
//	
//	return 0;
//}
