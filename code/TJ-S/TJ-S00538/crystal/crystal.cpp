#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long q[N],hh=1,tt;
long long cnt;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long siz=tt-hh+1;
		while(siz*a[i]-cnt>m&&siz){
			cnt-=q[hh++],siz--;
		}
		q[++tt]=a[i];
		cnt+=a[i];
		ans=max(ans,tt-hh+1);
	}
	cout<<ans<<endl;
	return 0;
} 
