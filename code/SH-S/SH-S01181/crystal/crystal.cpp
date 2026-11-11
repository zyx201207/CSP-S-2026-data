#include<bits/stdc++.h>
using namespace std;
#define int long long
#define foR(i,a,b,c) for(int i=a;i<=b;i+=c)
#define For(i,a,b,c) for(int i=a;i>=b;i-=c)
#define il inline
il void file(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
const int maxn=5e5+5;
int n,m,a[maxn],diff[maxn],pre[maxn],pre2[maxn],l,cnt,ans;
signed main(){
	file();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	foR(i,1,n,1){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	pre[1]=a[1];
	foR(i,2,n,1){
		pre[i]=pre[i-1]+a[i];
	}
	pre2[1]=0;
	foR(i,2,n,1){
		pre2[i]=(i-1)*a[i]-pre[i-1];
	}
	foR(i,1,n,1){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			
		}
	}
	return 0;
}

