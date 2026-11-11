#include<bits/stdc++.h>
using namespace std;
long long c[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)	cin>>c[i];
	sort(c+1,c+n+1);
	d[0]=0;
	for(long long i=1;i<=n;i++)	d[i]=d[i-1]+c[i];
	long long ans,left=1,right;
	for(long long t=1;t<=n;t++){
		if(t*c[t]-d[t]>m){
			right=t-1;
			ans=right;
			break;
		}
	}
	while(right<n){
		right++;
		while((right-left+1)*c[right]-(d[right]-d[left-1])>m)	left++;
		ans=max(ans,right-left+1);
	}
	cout<<ans;
	return 0;
}

