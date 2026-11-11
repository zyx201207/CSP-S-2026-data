#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using ll=long long;
int n,ans;
ll m,a[N];
ll s1[N],s2[N],q1[N],q2[N];
ll calc(int l,int r){
	ll res;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;i++){
		res+=a[mid]-a[i];
	}
	for(int i=mid+1;i<=r;i++){
		res+=a[i]-a[mid];
	}
	return res;
}
bool check(int k){
	ll res=1e18+5;
	for(int i=1;i+k-1<=n;i++){
//		cout<<i<<" "<<i+k-1<<" "<<calc(i,i+k-1)<<"\n";
		res=min(res,calc(i,i+k-1));
	}
	return res<=m;
}
int l,r;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int qwq=a[1];
	if(qwq<0){
		for(int i=1;i<=n;i++) a[i]-=qwq;
	}
	for(int i=1;i<=n;i++)
		s1[i]=s1[i-1]+a[i],
		q2[i]=q2[i-1]+s1[i];
	for(int i=n;i>=1;i--)
		s2[i]=s2[i+1]+a[i],
		q1[i]=q1[i+1]+s2[i];
		
//	for(int i=1;i<=n;i++){
//		cout<<s1[i]<<" ";
//	}
//	puts("");
//	for(int i=1;i<=n;i++){
//		cout<<s2[i]<<" ";
//	}
//	puts("");
//	for(int i=1;i<=n;i++){
//		cout<<q1[i]<<" ";
//	}
//	puts("");
//	for(int i=1;i<=n;i++){
//		cout<<q2[i]<<" ";
//	}
//	puts("");
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

