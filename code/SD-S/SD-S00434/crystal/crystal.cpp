#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int b[200005];
int ans;
int check(int k){
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
		b[i]=abs(a[i]-k);
	sort(1+b,1+b+n);
	int an=0,v=0;
	for(int i=1;i<=n;i++){
		if(v+b[i]>m)break;
		v+=b[i];
		an++;
	}
	return an;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=a[1];i<=a[n];i++){
		int e=check(i);
		ans=max(ans,e);
	}
	cout<<ans;
	return 0;
}
