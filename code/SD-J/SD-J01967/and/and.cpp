#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005],v[200005];
void dfs(int now){
	if(now>n){
		int num=0;
		for(int i=1;i<=n;i++){
			num+=v[i];
		}
		if(num==m){
			long long sum=0;
			bool f=0;
			for(int i=1;i<=n;i++){
				if(v[i]){
					if(f==0)sum=a[i],f=1;
					sum&=a[i];
				}
			}
			ans=max(ans,sum);
		}
		return;
	}
	v[now]=1;
	dfs(now+1);
	v[now]=0;
	dfs(now+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		long long tot=a[1];
		for(int i=1;i<=n;i++){
			tot&=a[i];
		}
		cout<<tot;
		return 0;
	}
	if(m==2){
		long long best=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				best=max(best,a[i]&a[j]);
			}
		}
		cout<<best;
		return 0;
	}
	if(m==n-1){
		long long biggest=0;
		for(int i=1;i<=n;i++){
			long long largest=0;
			if(i==1)largest=a[2];
			else largest=a[1];
			for(int j=1;j<=n;j++){
				if(j!=i)largest&=a[j];
			}
			biggest=max(biggest,largest);
		}
		cout<<biggest;
		return 0;
	}
	bool AA=1;
	for(int i=1;i<=n;i++){
		if(ceil(log2(a[i]+1))!=floor(log2(a[i]+1))){
			AA=0;
		}
	}
	sort(a+1,a+1+n);
	if(AA){
		cout<<a[n-m+1];
		return 0;
	}
	long long last=a[n];
	for(int i=n;i>n-m;i--){
		last&=a[i];
	}
	cout<<last;
	return 0;
}
