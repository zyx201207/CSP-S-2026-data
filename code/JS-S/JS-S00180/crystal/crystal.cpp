#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m;
int a[N],s[N];
bool check(int i,int j){
	return (i-j+1)*a[i]-(s[i]-s[j-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int left=1,right=i,k=i;
		while(left<=right){
			int mid=(left+right)>>1;
			if(check(i,mid)) right=mid-1,k=mid;
			else left=mid+1;
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}
