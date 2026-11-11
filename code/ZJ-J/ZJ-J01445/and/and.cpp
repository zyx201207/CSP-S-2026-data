#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
map<int,int> mp;
struct s{
	int x,y;
}a[200010];
bool cmp1(s a,s b){
	return a.x>b.x;
}
bool cmp(s a,s b){
	if(a.y==b.y) return a.x>b.x;
	return a.y>b.y;
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=32;i++){
		mp[pow(2,i)-1]=1;
	}
	cin>>n>>m;
	int t=1,t1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		int sx=a[i].x;
		if(!mp[a[i].x]) t1=0;
		if(a[i].x!=i-1) t=0;
		while(sx){
			if(sx&1) a[i].y++;
			sx>>=1;
		}
	}
	if(t==1){
		cout<<n-m;
		return 0;
	}
	sort(a+1,a+n+1,cmp1);
	if(t1==1){
		cout<<a[m].x;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].x;
	for(int i=2;i<=m;i++){
		ans&=a[i].x;
	}
	cout<<ans;
}