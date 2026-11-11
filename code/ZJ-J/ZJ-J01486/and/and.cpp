#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
const int N=2e5+5;
int a[N];
void dfs(int x,int tot,int lst){
	if(n-x+1<lst)return;
	if(x>n or lst<=0){
		if(lst>0)return;
		else ans=max(ans,tot);
		return;
	}
	dfs(x+1,tot&a[x],lst-1);
	dfs(x+1,tot,lst);
}
int lowbit(int x){
	return x&(-x);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int maxx=-1,s=0;
	cin>>n>>m;
	bool flag=1,f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lowbit(a[i]+1)!=a[i]+1)flag=0;
		if(a[i]!=i-1)f=0;
		if(i==1)s=a[i];
		else s&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}else if(m==n){
		cout<<s;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}else if(n<=20){
		dfs(1,INT_MAX,m);
		cout<<ans;
	}else if(flag){
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(f){
		//mei shi jian le
		//wan le
		//qian mian de qu yu,xia ci zai lai tan suo ba
	}
	return 0;
}

