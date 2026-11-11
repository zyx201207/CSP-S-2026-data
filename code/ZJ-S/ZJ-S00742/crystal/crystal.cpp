#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long 
#define N 500005
#define int128 __int128_t
using namespace std;//100pts
int n;
ll m;
ll a[N];
int128 sum[N];
int128 cha[N];
int ans;
/*
inline bool check(int l,int r){
	ll res=0;
	for(int i=l;i<r;i++){
		res+=a[r]-a[i];
		if(res>m)return 0;
	}
	return res<=m;
}
inline bool kill1(){
	for(int i=1;i<=n;i++){//O(n^2logn)  
		int l=i,r=n,res=-1;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(check(i,mid)){
				res=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,res-i+1);
	}
	return 1;
}*/
int128 s=0;
void solve(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+cha[i];
	}
	int l=1,r=0;
	while(r<=n){
		if(s+(r-l)*cha[1+r]<=m){
			++r;
			s+=(r-l)*cha[r];
		}else{
			l++;
			s-=sum[r-1]-sum[l];
		}
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
