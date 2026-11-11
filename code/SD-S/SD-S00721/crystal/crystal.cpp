#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5,INF=1e9;
int n,m,a[N],s[N],ans;
bool check(int mid,int r){
	int x=s[r]-s[mid]-(mid-1)*(a[r]-a[mid]);
//	cout<<x<<" ";
	return x<=m;
}
int b_search(int l,int r,int R){
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,R)){
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
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		//把a1~ai-1全部改到 ai 
//		cout<<s[i]<<" ";
	}
//	while(1){//测试用 
//		int mid,r;
//		cin>>mid>>r;
//		cout<<check(mid,r);
//	}
	for(int i=1;i<=n;i++){
		int x=b_search(1,i,i);//二分求出可以改几个到ai
		ans=max(ans,i-x+1);
//		cout<<ans<<" "; 
	}
	cout<<ans; 
	return 0;
}
