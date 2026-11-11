#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxx=-3e17,minx=3e17;
const int N=5e5+5;
int a[N];
int b[N];
int prefix[N];
int calm(int l){
	int sdfz=3e17;
	for(int i=1;i<=n-l+1;i++){
		int ave=a[i+l-1];
		int ans=0;
		for(int j=i;j<=i+l-1;j++){
			ans+=abs(a[j]-ave);
		}
		sdfz=min(sdfz,ans);
	}
	return sdfz;
}
int find() {
	int l=1,r=n;
	while(l<r-1){
		int mid=(l+r)>>1;
		int sum=calm(mid);
		if(sum>m){
			r=mid-1;
		}
		if(sum<=m){
			l=mid;
		}
	}
	return l;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag1=1,flag2=1;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			flag1=0;
		}
		maxx=max(maxx,a[i]);
		minx=min(minx,a[i]);
	}
	for(int i=2;i<=n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			flag2=0;
		}
	}
	if(flag1){
		cout<<min(m+1,n);
		return 0;
	}
	if(flag2){
		if(m>a[2]-a[1]){
			cout<<min(n,m/(a[2]-a[1])+1);
		}
		else{
			cout<<0; 
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		prefix[i]=prefix[i-1]+a[i];
	}
	cout<<find();
	return 0;
}





























