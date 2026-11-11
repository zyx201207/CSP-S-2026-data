#include<bits/stdc++.h>
using namespace std;
long long n,maxx=-1,m,a[500005],sc[500005],c[500005],dp[500005];
vector <long long> cc[500005];
vector <long long> tt[500005];  
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]-a[i-1])!=(a[i+1]-a[i]) && i!=1 && i!=n){
			f2=0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=abs(a[i]-a[i-1]);
		sc[i]=sc[i-1]+c[i];
	}
	long long maxn=-1;
	if(f2){
		for(int i=2;i<=n;i++){
			if(sc[i]<=m){
				maxn=i;
			}
		}
		cout<<maxn-1;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(sc[i]<=m){
			cc[1].push_back(sc[i]);
		}
		for(int j=i+1;j<=n;j++){
			if((sc[j]-sc[i])>m){
				break;
			}
			cc[i].push_back(sc[j]-sc[i]);
		}
	}
	for(int i=1;i<=n;i++){
		long long len=cc[i].size();
		for(int j=0;j<len;j++){
			tt[j+i].push_back(cc[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		long long len2=tt[i].size();
		long long ans=0,sum=0;
		for(int j=len2-1;j>=0;j--){
			sum+=tt[i][j];
			if(sum<=m){
				ans++;
			}
			else{
				break;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx+1;
	return 0;
}