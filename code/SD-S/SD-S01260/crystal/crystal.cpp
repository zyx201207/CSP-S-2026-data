// 17:50 100 pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x;
	scanf("%lld",&x);
	return x;
}
const int N=5e5+10;
int a[N],p[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		p[i]=p[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;++i){
		int l=i+1,r=n,pos=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]*(mid-i+1)-(p[mid]-p[i-1])<=m)
				l=mid+1,pos=mid;
			else r=mid-1;
		}
		ans=max(ans,pos-i+1);
	}
	printf("%lld\n",ans);
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int read(){
//	int x;
//	scanf("%lld",&x);
//	return x;
//}
//const int N=5e5+10;
//int n,m,a[N],p[N];
//int sum(int l,int r){
//	return p[r]-p[l-1];
//}
//bool check(int l,int r){
//	int tar1=sum(l,r)/(r-l+1),tar2=tar1+1,tar3=tar1-1;
////	int p1=lower_bound(a+l,a+r+1,tar1)-a,
////		p2=lower_bound(a+l,a+r+1,tar2)-a;
//	int L=l,R=r,p1=l,p2=l,p3=l;
//	while(L<=R){
//		int mid=(L+R)>>1;
//		if(a[mid]<=tar1)
//			L=mid+1,p1=mid;
//		else R=mid-1;
//	}
//	L=l,R=r;
//	while(L<=R){
//		int mid=(L+R)>>1;
//		if(a[mid]<=tar2)
//			L=mid+1,p2=mid;
//		else R=mid-1;
//	}
//	L=l,R=r;
//	while(L<=R){
//		int mid=(L+R)>>1;
//		if(a[mid]<=tar3)
//			L=mid+1,p3=mid;
//		else R=mid-1;
//	}
//	int val1=tar1*(p1-l+1)-sum(l,p1)+sum(p1+1,r)-tar1*(r-p1),
//		val2=tar2*(p2-l+1)-sum(l,p2)+sum(p2+1,r)-tar2*(r-p2),
//		val3=tar3*(p3-l+1)-sum(l,p3)+sum(p3+1,r)-tar3*(r-p3);
//	cerr<<"tar:  "<<tar1<<" "<<tar2<<" "<<tar3<<"\n";
//	cerr<<"p:    "<<p1<<" "<<p2<<" "<<p3<<"\n";
//	cerr<<"val:  "<<val1<<" "<<val2<<" "<<val3<<"\n";
//	return val1<=m||val2<=m||val3<=m;
//}
//signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	n=read(),m=read();
//	for(int i=1;i<=n;++i)
//		a[i]=read();
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;++i)
//		p[i]=p[i-1]+a[i];
//	cerr<<p[n]<<"\n";
//	cerr<<check(1,n)<<"\n";
///*
//10 100
//1 2 3 3 3 3 3 3 4 5
//*/
///*
//	int res=0;
//	for(int i=1;i<=n;++i){
//		int l=i+1,r=n;
//		while(l<=r){
//			int mid=(l+r)>>1; // cerr<<"("<<mid<<")";
//			if(check(i,mid))
//				l=mid+1;
//			else r=mid-1;
//		}
//		res=max(res,r-i+1);
////		cerr<<i<<" "<<res<<"\n";
//	}
//	printf("%lld\n",res);
//*/
//	return 0;
//}
///*
//Input #1:
//
//5 5
//1 2 4 8 9
//
//Output #1:
//
//3
//
//Input #2:
//
//5 8
//-3 -1 2 2 7
//
//Output #2:
//
//4
//
//*/
