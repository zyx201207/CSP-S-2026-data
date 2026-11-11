#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
typedef pair<int,int> PII;
int n,m;
int a[N];
int s[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		int l=i-x+1;
		int need=a[i]*(i-l+1)-(s[i]-s[l-1]);
		if(m>=need) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,best=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,best=mid;
		else r=mid-1;
	}
	cout<<best;
	return 0;
}
