#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N],m;
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j,cnt=0,maxx=0,last=1;
	long long cost=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	 for(i=1;i<=n;i++)
	 {
	 	cost+=cnt*(a[i]-a[i-1]);
	 	cnt++;
		while(cost>m)
		{
			cost-=a[i]-a[last];
			last++;
			cnt--;
		}
		 maxx=max(cnt,maxx);
	}
	cout<<maxx;
	return 0;
}
