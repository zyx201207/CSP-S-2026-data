#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long d[500050];
long long n,m;
long long sum[100050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	long long ans=1;
	for(long long i=2;i<=n;i++){
		if(d[i]<=m)ans=max(ans,i);
	}
	long long ans2=1;
	for(int i=1;i<=100005;i++){
		ans2=max(ans2,sum[i]);
	}
	cout<<max(ans,ans2);
	return 0;
}
