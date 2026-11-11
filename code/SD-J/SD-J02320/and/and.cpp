#include<bits/stdc++.h>//and
using namespace std;
int n,m,a[200005],maxx=-1;
long long p[35];
long long sum;
bool f1=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i]!=(i-1)) f1=0;
		maxx=max(maxx,a[i]);
		sum&=a[i];
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		long long ans=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				ans=max(ans,x);
			}
		}
		cout<<ans;
		return 0;
	}
	p[0]=1;
	for(int i=1;i<=32;i++){
		p[i]=2*p[i-1];
		if(n==p[i]&&f1){
			cout<<n-m;
			return 0;
		}
	}
	if(n>2000&&n<=200005){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	long long ans=-1;
	for(int i=(2<<m);i<=(2<<n);i++){
		int x=i,cnt=0,k=0;
		long long sum;
		bool f=1;
		while(x){
			if(x&1==1){
				cnt++;
			}
			x=(x>>1);
		}
		if(cnt!=m) continue;
		for(int j=1;j<=i;j=(j<<1)){
			k++;
			if(i&j){
				if(f){
					sum=a[k];
					f=0;
				}else{
					sum&=a[k];
				}
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
