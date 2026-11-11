#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
    	long long maxn=LLONG_MIN;
    	for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn<<'\n'; 
	}
	else if(m==n){
		long long sum=0;
		for(int i=1;i<=n;i++) sum&=a[i];
		cout<<sum<<'\n';
	}
	else if(m==2){
		long long maxn=LLONG_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn<<'\n';
	}
	else if(m==n-1){
		int c=0;
		long long maxn=LLONG_MIN;
		while(c<=n){
			c++;
			long long sum=0;
			for(int i=1;i<=n;i++) if(i!=c) sum&=a[i];
			maxn=max(maxn,sum);
		}
		cout<<maxn<<'\n';
	}
	else cout<<0<<'\n';
    return 0;
}
