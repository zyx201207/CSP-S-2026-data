#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,inf=0x3f3f3f3f3f3f3f3f;
int c,t,n,m,ans,a[N];
int mi,cnt;
bool A=1;
void dfs(int x,int to,int sum){
	if(x>to)return;
	if(x==to){
		if(sum<mi)mi=sum,cnt=1;
		else if(sum==mi)cnt++;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>m)break;
		dfs(i,to,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;ans=0;
		int miu=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2)if(a[i]-a[i-1]!=miu)A=0;
			miu=a[i]-a[i-1];
		}
		if(A){
			if(m==2*miu)cout<<n-3<<endl;
			else if(m<2*miu)cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				mi=inf,cnt=0;
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
