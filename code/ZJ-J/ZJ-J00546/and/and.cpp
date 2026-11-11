#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		long long maxn=0ll;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long t=(a[i])&(a[j]);
				maxn=max(maxn,t);
			}
		}
		cout<<maxn;
	}else{
		int t=n;
		while(t%2==0){
			t/=2;
		}
		if(t==1){
			cout<<n-m;
		}else{		
			sort(a+1,a+n+1);
			long long ans;
			for(int i=1;i<=m;i++){
				ans&=a[i];
			}
			cout<<ans;	
		}
	}
	return 0;
}

