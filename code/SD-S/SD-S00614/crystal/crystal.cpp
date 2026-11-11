#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long b[500010];
int ans=1;
int mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	int fg=1;
	long long mnn=LLONG_MAX;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1] && i!=2){
			fg=0;
		}
		mnn=min(mnn,b[i]);
	}
	if(fg){
		m=m/b[2];
		long long xxxxx=1;
		while(m>0 && m>=xxxxx){
			m-=xxxxx;
			xxxxx++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(mnn>m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		int j=i;
		while(sum+a[j]<=m &&j<=n){
			sum+=b[j]*(j-i+1);
			j++;
		}
		mx=max(mx,(j-i+1));
	}
	cout<<mx;
	return 0;
}
