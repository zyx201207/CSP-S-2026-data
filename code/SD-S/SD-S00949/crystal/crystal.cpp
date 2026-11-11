#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int a[N];
int pre[N];
int n,m;
//priority_queue<int,vector<int>,greater<int>> q;
int j=1;
bool check(int x){
	int cnt=0;
	int t;
	int num=0;

	for(int i=j;i<=n;i++){
		if(a[i]<=x) cnt++,t=i,num+=abs(x-a[i]);
	}
//	cout<<x<<" "<<num<<endl;
//	int need=cnt*x;
//	cout<<x<<" "<<cnt<<endl;
	return num<=m;
}
map<int,int> mp;
void solve(){
	cin>>n>>m;
	int minn2=1e12;
	int maxx2=-1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn2=min(minn2,a[i]);
		maxx2=max(maxx2,a[i]);
		pre[i]=pre[i-1]+a[i];
		mp[a[i]]++;
	}
	int ans=0;
	sort(a+1,a+1+n);


	bool flag=true;
	for(int i=1;i<n;i++){
		if(abs(a[i+1]-a[i]<=m)) flag=true;	
		else flag=false,j=i+1;
	}
//	if(flag==true) j=1;
//	cout<<j<<endl;
	int l=minn2,r=maxx2;
//	while(check(r)) r<<=1;
//	while(check(l)) l<<=1;
//	cout<<r<<endl;
//	cout<<l<<endl;
	while(l<r){
//		cout<<l<<" "<<r<<endl;
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	int maxx=-1e12;
	int ans2=0;
	for(int i=1;i<n;i++){
		int d=a[i+1]-a[i];
		if(d<=m) ans2=2;
	}
	for(int i=j;i<=n;i++){
		if(a[i]<=l) ans++;
		maxx=max(maxx,mp[a[i]]);
	}
	cout<<max(maxx,max(ans,ans2));
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
	while(_--) solve();
	return 0; 
}

