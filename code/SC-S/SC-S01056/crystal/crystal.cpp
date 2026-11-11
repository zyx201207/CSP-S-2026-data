#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+1;
int n,m;
int a[MAXN];
int pre[MAXN];
//priority_queue<int,vector<int>,greater<> > q;
int cnt;
int ans=-1;
bool check(int x){
	return x<=m;
}
int bin(int idx,int lft,int rgt){
	int i=idx,l=lft,r=rgt;
//	cout<<i<<' '<<l<<' '<<r<<' ';
	int mid=(l+r)/2;
	int res=r;
	while(l<=r){
		mid=(l+r)/2;
		if(check((i-1-mid)*a[i]-pre[i-1]+pre[mid])){
			res=mid;
			r=mid-1;
//			cout<<"1 ";
		}else{
			l=mid+1;
//			cout<<"2 ";
		}
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
//		while((i-1-cnt)*a[i]-pre[i-1]-pre[cnt]>m){
//			q.pop();
//			++cnt;
//		}
//		if((i-1-l)*a[i]-pre[i-1]-pre[l]>m){
//			q.pop();
//			++l;
//		}
		if((i-1-cnt)*a[i]-pre[i-1]+pre[cnt]>m){
			int t=bin(i,cnt,i);
			cnt=t;
		}
//		q.push(a[i]);
		ans=max(ans,i-cnt);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

/*
2 998244353123456
1145141919810 1919810114514
*/