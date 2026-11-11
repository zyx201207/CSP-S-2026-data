#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool B=1,A=1;
void dfs(int k,int an,int l){
//	printf("dfs(%d,%d,%d)",k,an,l);
	if(k>m){
		ans=max(ans,an);
		return;
	}
	for(int i=l+1;i<=n-m+k;++i){
		dfs(k+1,an&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
//		cout<<(a[i]&(a[i]+1));
		if(A&&((a[i]&(a[i]+1))!=0))A=0;
		if(B&&a[i]!=i-1)B=0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(A){
		sort(a+1,a+n+1);
		ans=a[n-m+1];
		cout<<ans;
		return 0;
	}
	if(B){
		ans=a[n];
		for(int i=n-1;i>=n-m+1;--i){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-m+1;++i){
		dfs(2,a[i],i);
	}
	cout<<ans;
}
