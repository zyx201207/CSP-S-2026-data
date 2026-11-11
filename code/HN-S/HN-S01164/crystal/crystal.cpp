#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
long long cha[500005];
bool check(int idx,int cnt){
	int k=cha[idx]-cha[cnt+1]-(cnt-idx+1)*(a[n]-a[cnt]);
	return k<=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cha[i]=cha[i+1]+a[n]-a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i,res=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid,i)){
				res=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
			ans=max(ans,i-res+1);
		} 
	}
	cout<<ans;
	return 0;
} 
