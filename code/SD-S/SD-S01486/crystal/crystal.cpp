#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

const int N=5e5+5;

long long n,m;

long long a[N];

long long cf[N];
long long qz[N];

int main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	cin>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) cf[i]=a[n]-a[i];
	for(int i=n;i>=1;i--) qz[i]=qz[i+1]+cf[i];
	/*
	for(int i=1;i<=n;i++) cout<<cf[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<qz[i]<<" ";
	cout<<"\n";
	*/
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r)>>1;
			
//			cout<<i<<" "<<mid<<" "<<qz[mid]-qz[i+1]-(i-mid+1)*cf[i]<<"\n";
			
			if(qz[mid]-qz[i+1]-(i-mid+1)*cf[i]<=m) r=mid;
			else l=mid+1;
		}
		
		ans=max(ans,(i-l+1));
	}
	
	cout<<ans;
	
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
