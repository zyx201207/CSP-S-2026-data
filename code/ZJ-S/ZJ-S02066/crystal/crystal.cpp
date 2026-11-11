#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc_ getchar()
inline int read(){
	int x=0,f=1;char ch=gc_;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc_;}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc_;}
	return x*f;
}
int n,m,a[500005],b[500005],sum=-1e9;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid,len,need;
		while(l<r){
			mid=((l+r)/2)+1;
			len=mid-i+1,need=len*a[mid]-(b[mid]-b[i-1]);
//			if(len>3845&&len<=4236)cout<<i<<" "<<mid<<" "<<len<<" : "<<need<<endl;
			if(need>m)r=mid-1;
			else l=mid;
		}
		sum=max(sum,l-i+1);
	}
	cout<<sum;
	return 0;
} 
/*
我-作为一名oier，已经没有什么事情可以让我睁眼了；
q-第一题写了一个小时；
我-没事，至少做出来了；
q-爆零了；
我-纳尼？！ 
*/
