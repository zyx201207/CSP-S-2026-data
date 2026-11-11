#include<bits/stdc++.h>
using namespace std;
long long vis[500005];
long long a[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long flag=0;
	for(long long j=20;j>=0;j--){
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if(vis[i]==1) continue;
			long long k=(a[i]>>j)&1;
			cnt+=k;
		}
		if(cnt>=m){
			flag=1;
		}
		else{
			continue;
		}
		for(long long i=1;i<=n;i++){
			long long k=(a[i]>>j)&1;
			if(flag==1&&k==0){
				vis[i]=1;
			}
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(vis[i]==0){
			ans=i;
			break;
		}
	}
	long long xx=a[ans];
	long long cnt=1;
	for(long long i=1;i<=n;i++){
		if(ans==i)continue;
		if(vis[i]==0){
			cnt++;
			xx=xx&a[i];
			if(cnt==m) break;
		}
	}
	if(cnt<m) {
		cout<<0<<endl;
		return 0;
	}
	cout<<xx<<endl;
}
