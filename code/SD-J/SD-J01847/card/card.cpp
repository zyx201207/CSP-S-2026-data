#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans[200005],sum[200005],l,r;
long long find(long long x,long long j){
	for(long long i=1;i<=j;i++){
		if(ans[i]==x){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		l=0,r=0;
		for(long long i=1;i<=n;i++){
			ans[i]=0;
		}
		for(long long j=i;j<=n;j++){
			long long cnt=find(a[j],r);
			if(cnt==0){
				r++;
				ans[r]=a[j];
			}else{
				r=cnt;
			}
		}
		for(long long i=1;i<=r;i++){
			sum[ans[i]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
