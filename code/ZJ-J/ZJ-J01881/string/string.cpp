#include<bits/stdc++.h>
#define int long long
#define db(x) cout<<#x<<" "<<x<<endl;
using namespace std;
int n;
int a[200005],b[200005],f[200005],s,p[400005];
int color(int k){
	int l=1,r=n+1;
	while(l<r){
		int mid=(l+r+1)/2;
		if(f[mid]<k)l=mid;
		else r=mid-1;
	}
	return b[l];
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	f[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;
		cin>>c;
		b[i]=c-'a'+1;
		s+=a[i];
		p[i]=p[i-1]+a[i];
		f[i+1]=p[i];
	}
	p[n+1]=a[n];
	for(int i=2;i<=n;i++){
		p[n+i]=p[n+i-1]+a[n+1-i];
	}
	sort(p+1,p+2*n+1);
	int k=unique(p+1,p+2*n+1)-p,ans=0;
	for(int i=1;i<=(k-1)/2;i++){
		if(color(p[i])!=color(p[k-i]))ans+=p[i]-p[i-1];
	}
	cout<<ans;
	return 0;
}
/*
4
2 a
3 b
1 c
2 d
*/