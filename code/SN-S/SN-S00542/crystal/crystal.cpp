#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxn=INT_MIN;
ll n,m,sum[500005],a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		sort(a+1,a+n+1);
		for(int i=n;i>1;i--){
			if(a[i]==a[i-1]) continue;
			int k=1;
			ll l=m;
			ll p=a[i]-a[i-k];
			while(l-p*sum[a[i-k]]>=0&&i>=k){
				l-=p*sum[a[i-k]];
				sum[a[i]]+=sum[a[i-k]];
				k++;
				p=a[i]-a[i-k];
				
			}
			sum[a[i]]+=min(l/p,sum[a[i-k]]);
		}
		for(int i=1;i<=n;i++){
			maxn=max(maxn,sum[a[i]]);
		}
		
	}
	else{
		maxn=1;
		ll k=a[2]-a[1],ans=1;
		while(m>0&&maxn<n){
			m-=k*ans;
			ans++;
			maxn++;
		}
	}
	cout<<maxn<<endl;
	return 0;
}


