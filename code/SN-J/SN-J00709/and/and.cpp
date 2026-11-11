//li wen lin
//xi an shi yuan dong di er zhong xue
//SN-J00709
#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[20010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==2){
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				ans=max(ans,a[i]|a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n){
		long long ans=a[1];
		for(long long i=2;i<=n;i++){
			ans=ans|a[i];
		}
	}
	else if(m==n-1){
		long long ans=a[1];
		long long maxn=0;
		for(long long i=2;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(j==i)
				    continue;
				else{
					ans|a[j];
				}
			}
			maxn=max(maxn,ans);
		}
	}
	return 0;
	
}

