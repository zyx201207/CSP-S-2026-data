#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
int ans;

bool check(int mid,int x){
	return a[x]*(x-mid)-(s[x-1]-s[mid-1])<=m;
}

int get(int x){
	int l=1,r=x;
	for(int i=1;i<=20;i++){
		int mid=(l+r)>>1;
		if(check(mid,x)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,i-get(i)+1);
	}
	cout<<ans<<'\n';
	return 0;
}