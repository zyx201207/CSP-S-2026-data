#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+10; 
long long n,m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long minn=a[1];
	long long maxx=a[n];
	long long l=minn,r=maxx;
	while(l <= r){
		long long mid=(l+r)/2;
		long long res=0;
		for (long long i=n;i>=1;i--){
			if (a[i] > mid) continue;
			res+=(mid-a[i]);
		}
		if (res > m){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	long long cnt=0;
	long long dis=0;
	sort(a+1,a+n+1);
	bool flag=false;
	for (long long i=1;i<=n;i++){
		if (a[i] >r){
			dis=i-1;
			flag=true;
			break;
		}
	}
	if (!flag) dis=n;
	long long cha=0;
	for (long long i=dis;i>=1;i--){
		cha+=(r-a[i]);
		if (cha > m){
			break;
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
} 
