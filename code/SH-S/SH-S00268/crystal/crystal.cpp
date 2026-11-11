#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
double s1=0;
vector<int> a(500010);
vector<int> d(500010);
int cnt=0;

int check(int mid,int m){
	for(int i=1;i<=n;i++){
		d[i]=abs(a[i]-mid);
	}
	sort(d.begin(),d.end());
	int ans=0;
	for(int i=1;i<=n;i++){
		if(m>=d[i]){
			m-=d[i];
			ans++;
		}
		else break;
	}
	return ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin>>n>>m;
	int mn=1e12,mx=-1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	int cnt=0;
	for(int i=mn;i<=mx;i++){
		d.clear();
		int q=check(i,m);
		if(q>cnt) cnt=q;
	}
	cout<<cnt;
	return 0;
}
