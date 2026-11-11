#include <bits/stdc++.h>
using namespace std;
int a[500005],vis[500005];
vector<int> v;
//bool dp[50005];
int cnt=0;
struct Node{
	int v,w;
};
bool check2(){
	for(int i=1;i<v.size();++i){
		if(abs(a[i]-a[i-1])>2){
			return 1;
		}
	}
	return 0;
}
int dp[1000005];
void dfs(int b,int e,int j){
	if(b==e+1){
		if(check2()){
			cnt++;
		}
		
		return ;
	}
	for(int i=b;i<=j;++i){
		//if(i>b && a[i]==a[i-1]) continue;
		if(!vis[i]){
			vis[i]=1;
			v.push_back(a[i]);
			dfs(b+1,e,j);
			vis[i]=0;
			v.pop_back();
		}
	}
}
int check(int k,int n){
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1]>k){
			return i;
		}
	}
	return -1;
}
int f(int k,int d){
	if(1<=k && k<=d) return 1;
	if(dp[k-d]!=-1){
		return dp[k-d]+f(d,d);
	}else if(dp[d]!=-1){
		return dp[d]+f(k-d,d);
	}else{
		return dp[d]+dp[k-d];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	memset(dp,-1,sizeof(dp));
	int c,T,n,d,x;
	cin>>c>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
//		int k=check(d,n);
//		n=n-(n-k+1);
		int ans=1;
		for(int j=n;j<=2;--j){
			dfs(1,2,j);
			if(cnt==2){
				ans++;
			}
//			if(f(j,d)==2){
//				ans++;
//			}
		}
		
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

