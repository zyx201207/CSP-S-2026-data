#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int a[N],n,m;ll mx=-1,s;
int ans[N];
ll ad(ll a,ll b){
	ll res=0;int w=1;
	while(min(a,b)){
		if((a&1)&&(b&1)){
			res+=w;
		}
		a>>=1;b>>=1;w<<=1;
	}
	
	return res;
}
ll sum(){
	ll res=0XFFFFFFFFFFF;//11111
	for(int i=1;i<=m;++i){
		res=ad(res,ans[i]);
	}
	return res;
}
void dfs(int w,int c){
	if(w>n){
		if(c==m+1){
			mx=max(sum(),mx);
//			for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
//			cout<<"\n";
//			cout<<sum()<<" "<<mx<<"\n";
		}
		return;
	}
	dfs(w+1,c);
	
	ans[c]=a[w];
	dfs(w+1,c+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n==m){
		ll res=0XFFFFFFFFFFF;
		for(int i=1;i<=n;++i){
			res=ad(res,a[i]);
		}
		cout<<res;
		return 0;
	}
	else if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
		return 0;
	}
	else if(n<=30){
			dfs(1,1);//w:1 c:0
			cout<<mx;
			return 0;
	}
	else {//A
		sort(a+1,a+n+1,greater<int>());
		ll res=0XFFFFFFFFFFF;
		cout<<a[m];
		return 0;
	}

}
