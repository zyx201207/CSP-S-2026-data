#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=5e5+5;
int n,m,a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n,best=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid]*(mid-i+1)-pre[mid]+pre[i-1]<=m){
				best=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,best-i+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7

3845

315275
输出的小了 

4 3
1 2 4 4

6 5
1 2 3 4 5 6


*/
