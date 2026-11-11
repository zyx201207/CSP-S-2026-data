#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
/*
先排序，每次使尽可能多的前面的数变成自己 
二分找到第一个代价在m以内的 
100pts
*/ 
const int N=5e5+5;
int n,m,a[N],s[N];
bool check(int l,int r,int to){
	int k=(r-l+1)*to-(s[r]-s[l-1]);
	return k<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i,a[i])){
				r=mid-1;
				res=i-mid+1;
			}
			else l=mid+1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}

