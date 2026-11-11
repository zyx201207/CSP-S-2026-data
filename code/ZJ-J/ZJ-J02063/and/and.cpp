#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[200005],cnt,ans,f;
void dfs(int x,int sta){
	if(x>m){
		int s=a[b[1]];
		for(int i=2;i<=m;i++) s&=a[b[i]];
		ans=max(ans,s);
		return;
	}
	for(int i=sta+1;i<=n;i++){
		b[x]=i;
		dfs(x+1,i);
	}
}
bool B(int x){
	int k=1;
	while(k<x) k*=2;
	return (k==x);
}
bool A(){
	for(int i=1;i<=n;i++){
		int x=a[i]+1;
		if(pow(2,log2(x))!=x) return 0;
	}
	return 1;
}
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20||m<=2){//45 pts
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	if(B(n)){//10 pts
		for(int i=1;i<=n;i++)
			if(a[i]!=i-1) f=1;
		if(f==0){
			int s=n-1,t=n-1;
			for(int i=1;i<m;i++){
				t--;
				s=s&t;
			}
			cout<<s;
			return 0;
		}
	}
	if(A()){//5 pts
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)
		ans=ans&a[i];
	cout<<ans;
}