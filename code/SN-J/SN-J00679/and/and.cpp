//zuoxianke 西安铁一中学 SN-J00679
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],maxn=0;
void dfs(int x,int y,int sum){
	if(y>m)return;
	if(x>n){
		if(y<m)return;
		maxn=max(maxn,sum);
		return;
	}
	dfs(x+1,y,sum);
	dfs(x+1,y+1,sum&a[x]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1,0,(1<<31)-1);
		cout<<maxn;
	}else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
			cout<<maxn;
			return 0;
		}else if(m==n){
			maxn=a[1];
			for(int i=2;i<=n;i++)maxn&=a[i];
			cout<<maxn;
			return 0;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
			cout<<maxn;
			return 0;
		}
	}else{
		int maxa=0;
		for(int i=1;i<=n;i++)maxn=max(maxa,a[i]);
//		if(maxa<4){
			sort(a,a+n);
			maxn=a[n];
			for(int i=n-1;i>=n-m+1;i--){
				maxn&=a[i];
			}
			cout<<maxn;
			return 0;
//		}
	}
}
