#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=500010;

LL n,m,a[N],s[N];

bool check(int x){
	LL cnt=1e18;
	for(int i=x;i<=n;i++){
		cnt=min(cnt,a[i]*(x-1)-(s[i-1]-s[i-x]));
	} 
	return cnt<=m;
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
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	
	return 0;
} 


