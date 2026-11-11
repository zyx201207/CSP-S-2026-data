#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int a[N],sum[N],n,m;

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}

inline bool check(int x,int y){//[x,y] => a[y] 是否足够 
	int len=(y-x+1);
	return (a[y]*len-(sum[y]-sum[x-1]))<=m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i]; 
	//逐个枚举以哪一个为最大值，计算有多少个可以加到相同数值
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;//可以加到的部分的左端点，二分寻找
		while(l<r){
			int mid=((l+r)>>1);
			if(check(mid,i)) r=mid;
			else l=mid+1;
		} 
		ans=max(ans,i-r+1);
	} 
	cout<<ans;
	return 0;
}
/*
应该也可以算作是水题
感觉就是逐个枚举哪一个作为最大值，然后把其他的加过来 

5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/ 