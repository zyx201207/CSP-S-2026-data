#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[100];
	cin>>n>>m;
	long long ans=0;
	for(long long i=1;i<=n;i++)
			cin>>a[i];
	if(m==2){
		for(long long i=1;i<=n;i++){
			long long s1=a[i];
			for(long long j=i+1;j<=n;j++){
				long long s2=a[j];
				ans=max(ans,s1&s2);
		}
	}	
	}
	if(m=3){
		for(long long i=1;i<=n;i++){
			long long s1=a[i];
			for(long long j=i+1;j<=n;j++){
				long long s2=a[j];
				for(long long z=j+1;z<=n;z++){
					long long s3=a[z];
					ans=max(ans,s1&s2&s3);
				}
				    
		}
	}	
	}
	cout<<ans;
	return 0;
}

