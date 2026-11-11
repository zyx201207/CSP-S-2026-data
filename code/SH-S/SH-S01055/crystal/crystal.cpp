#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m;

ll s[500005];

ll pre[500005];

bool check(int mid){
	bool res=0;
	for(int r=mid;r<=n;++r){
		ll sum=pre[r]-pre[r-mid];
		if(s[r]*mid-sum<=m) res=1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i];
	
	sort(s+1,s+n+1);
	
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+s[i];
	
	int l=1,r=n+1;
	// l <= ans, r > ans
	while(r-l>1){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	
	cout<<l<<endl;
	
	return 0;
}
