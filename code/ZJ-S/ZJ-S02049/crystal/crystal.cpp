#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],sum[N];
bool check(int x,int q){
	if((x-q)*1ll*a[x]-sum[x-1]+sum[q-1]<=m) return 1;
	else return 0;
}
int solve(int p){
	int l=1,r=p-1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(p,mid)) r=mid;
		else l=mid+1;	
	}
	return (p-l+1);
} 

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		ans=max(ans,solve(i));
	}
	cout<<ans;
	return 0;
}

