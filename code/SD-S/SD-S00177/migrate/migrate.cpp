#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int a[N];
int minn,cnt;
void dfs(int root,int fr,int sum,int x){
	if(root>x) return ;
	if(root==x){
		if(sum<minn){
			minn=sum;
			cnt=1;
		}else if(minn==sum) cnt++;
		//cout<<x<<" "<<minn<<" "<<sum<<" "<<cnt<<"\n";
		return ;
	}
	if(sum>=minn) return ;
	for(int i=root+1;i<=x;i++){
		//cout<<"fr:"<<fr<<" r:"<<i<<" dt:"<<a[i]-a[fr]<<"\n";
		if(a[i]-a[root]<=d) dfs(i,root,sum+1,x);
		else break;
	}
}
void solve(){
	memset(a,0,sizeof(a));
	cin>>n>>d;
	//cout<<n<<" "<<d<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=4;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			minn=1e18+10;
			cnt=0;
			int j=i+l-1;
			//cout<<i<<" "<<j<<"\n";
			dfs(i,i,0,j);
			if(cnt==2) ans++;
		} 
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
