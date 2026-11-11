#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],s[N];
bool check(int x,int i){
	int s1=a[i]*(i-x+1);
	int s2=s[i]-s[x-1];
	return (m>=s1-s2);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ans=0;
	for(int i=2;i<=n;i++){
		int l=1,r=i,an=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				an=max(an,i-mid+1);
			}else l=mid+1;
		}
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
}