#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,res;
vector<int> a;
bool check(int k){
	vector<int> b;
	int cnt=0,ans=0;
	for(int i=0;i<n;i++){
		int x=abs(a[i]-k);
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	for(int i:b){
		if(cnt>=1e18-i) break;
		if((cnt+i)<=m) cnt+=i,ans++;
		else break;
	}
	if(ans>=res){
		res=ans;
		return 1;
	}
	return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie();
    cin>>n>>m;
    int l=0,r=0;
    for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		a.push_back(t);
		r=max(r,t);
	}
    sort(a.begin(),a.end());
    while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) r=mid-1;
		else l=mid;
	}
	cout<<res;
    return 0;
}
