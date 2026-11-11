#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50010],b[50010],ans1=-1e8,ans;
int dfs(int x,int y){
	long long sum=0,cnt=0;
	for(long long i=x+1;i<=y;i++){
		b[i-1]=a[i]-a[1];
	}
	for(int i=x;i<y;i++){
		sum=b[i];
		if(m<b[i]) break;
		m-=b[i];
		cnt++;
	}
	for(long long i=1;i<=n;i++){
		if(sum==b[i]) cnt++;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		b[i-1]=a[i]-a[1];
	}
	for(long long i=2;i<n;i++){
		for(long long j=i+1;j<n;j++){
			ans=dfs(i,j); 
			ans1=max(ans1,ans);
		}
	}
	if(ans1>=n) cout<<n;
	else cout<<ans1+1;
	return 0;
}