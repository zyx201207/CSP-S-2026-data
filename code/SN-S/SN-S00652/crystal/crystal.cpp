#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500005],ans;
inline int query(int x){
	//让所有数增加至 x，能有多少个相同的数
	int num=m,qwq=0,pos=0;
	for(int i=1;i<=n;i++){
		if(a[i]<x){
			pos=i;
		}
		if(x==a[i]){
			qwq++;
		}
		if(a[i]>x){
			break;
		}
	}
	for(int i=pos;i>=1;i--){
		if(x-a[i]<=num){
			num-=(x-a[i]);
			qwq++;
		}
	}
	return qwq;
}
int minn=LONG_LONG_MAX,maxx=LONG_LONG_MIN;
inline void solve_A(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return;
		}
	}
	int l=1,r=sqrt(4e18);
	while(l<r){
		//第一个 (x-1)x/2-1>=m
		int x=(l+r)/2;
		if((x-1)*x/2-1>=m){
			r=x;
		}
		else{
			l=x+1;
		}
	}
	cout<<min(l-1,n)<<endl;
	exit(0);
	return;
}
inline void solve_B(){
	int st=a[1],d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			return;
		}
	}
	int l=1,r=sqrt(2e18/d);
	while(l<r){
		int x=(l+r)/2;
		if((x-1)*x/2*d-1>=m){
			r=x;
		}
		else{
			l=x+1;
		}
	}
	cout<<min(l-1,n)<<endl;
	exit(0);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	system("fc crystal.out crystal4.ans");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]),maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	solve_A();
	solve_B();
//	for(int i=minn;i<=maxx;i++){
//		ans=max(ans,query(i));
//	}
//	cout<<ans<<endl;
//	for(m=1;m<=100;m++){
		ans=0;
		for(int i=minn;i<=maxx;i++){
//			cout<<i<<"->"<<query(i)<<endl;
			ans=max(ans,query(i));
		}
//		cout<<"m:"<<m<<"->"<<ans<<endl;
//	}
	cout<<ans<<endl;
	return 0;
}
