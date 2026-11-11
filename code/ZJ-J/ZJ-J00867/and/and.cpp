#include <bits/stdc++.h>
using namespace std;
int n,c,ans,maxn,b[200100];
struct lmq{
	int x,y;
}a[200100];
int cmp(lmq u,lmq v){
	return u.y>v.y;
}
//void dfs(long long x,long long y){
//	if(x==c){
//		ans=max(ans,y);
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(b[i]==0){
//			b[i]=1;
//			dfs(x+1,y&a[i]);
//			b[i]=0;
//		}
//	}
//}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		b[a[i].x]++;
		maxn=max(maxn,a[i].x);
	}
	for(int i=1;i<=maxn;i++){
		if(b[i]==c){
			cout<<i;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int q=a[i].x;
		while(q!=0){
			if(q%2==1){
				a[i].y++;
			}
			q=q/2;
		}
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].x;
	for(int i=1;i<=n;i++){
		cout<<a[i].x<<" ";
	}
	for(int i=2;i<=c;i++){
		ans=ans&a[i].x;
	}
	cout<<ans;
	return 0;
}
