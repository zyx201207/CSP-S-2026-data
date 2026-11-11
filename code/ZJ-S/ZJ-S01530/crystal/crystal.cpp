#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+20;
int n,m,l,r,mid,ans;
int a[N],s[N];
bool check(int cnt,int k){
	int pos=k-cnt+1;
	int sum=s[k]-s[pos-1];
	if(a[k]*cnt-sum<=m) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	for(int i=1;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			mid=l+(r-l>>1);
			if(check(mid,i)){
				ans=max(ans,mid);
				l=mid+1;
			}else r=mid-1;
		}
	}
	cout<<ans;
	
	return 0;
}
