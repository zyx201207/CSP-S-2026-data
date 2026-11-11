#include<bits/stdc++.h> 
using namespace std;
int a[5000005];
long long b[5000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=0;i<=n;++i){
		b[i]=a[i]-a[i-1];
	
	}
	long long ans=-1;
	for(int i=1;i<=n;++i){
		long long cost=0,maxn=1;
		for(int j=i+1;j<n;++j){
			int time=1;
			cost+=b[j]*time;
			if(cost<=m){
				maxn++;
			}
			else{
				break;
			}
		}
	}
	for(int i=n;i>0;--i){
		int maxn=0;
		for(int j=i;j>0;--j){
			if(a[i]+a[j]>m){
				maxn=a[i]-a[j];
				break;
			}
		}
		ans=maxn;
	}

	cout<<ans;
	return 0;
}
