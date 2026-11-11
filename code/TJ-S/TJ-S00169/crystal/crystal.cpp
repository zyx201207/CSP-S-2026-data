#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,minn=INT_MAX;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]*1ll);
	}
	if(minn<0){
		for(int i=1;i<=n;i++){
			a[i]+=abs(minn);
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		long long sum=0;
		int u=m;
		int k=i;
		int cnt=1;
		while(u>=0&&k<n){
			int last;
			u-=cnt*(a[k+1]-a[k]);
			sum++;
			cnt++;
			k++;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
