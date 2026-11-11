//long long
//清空文件夹其他文件
//freopen!!!文件名+别注释 
//线段树开4倍，小心N的+10，小心越界未定义行为!!! 
//别用endl 
//考虑各种特例 
//初始化问题!! 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=5e5+10;

int n;
long long m;
long long a[N];
long long c[N];

bool Judge(int l,int r){
	long long sm=c[r]-c[l-1];
	long long nd=1ll*(r-l+1)*a[r];
	nd=nd-sm;
	return nd<=m;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	c[0]=0;
	for(int i=1;i<=n;++i){
		c[i]=c[i-1]+a[i];
	}
	
	int ans=1;
	
	for(int i=1;i<=n;++i){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(Judge(mid,i)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1); 
	}
	
	cout<<ans<<'\n';
	
	return 0;
} 
