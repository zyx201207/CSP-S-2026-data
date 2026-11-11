#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=2e6+7;
int c,t,n,d,a[maxn],ans,sum;
void ddfs(int x,int y,int step){
	if(x==y){
		ans=min(ans,step);
		return;
	}for(int i=y;i>x;--i)
		if(abs(a[i]-a[x])<=d){
			ddfs(i,y,step+1);return;
		}
}int dfs(int x,int y,int step){
	if(step>ans)return(0);
	if(x==y)return(1);
	int ret=0;
	for(int i=x+1;i<=y;++i)
		if(abs(a[i]-a[x])<=d)
			ret+=dfs(i,y,step+1);
	return(ret);
}signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(cin>>c>>t;t--;){
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j){
				ans=017777777777,ddfs(i,j,0);
				if(dfs(i,j,0)==2)++sum;
//				cout<<i<<' '<<j<<' '<<sum<<'\n';
//				if(i==1&&j==5)cout<<ans<<"---\n";
			}
		cout<<sum<<'\n',sum=0;
			
			
			
			
//		for(int i=2;i<=n;++i){
//			vector<int>f(n+1)
//			for(int k=1;k<i;++k){
//				f[k]=1;
//				for(int j=k;j<i;++j){
//					if(a[i]-a[j]<=d)f[i]+=f[j];
//					
//				}
//				
//			}
//		}
// 
//		for(int i=1;i<=n;++i){
//			for(int j=i;j<=n;){
//				int k=upper_bound(a+j+1,a+n+1,a[j]+d)-a;
//				
//			}
//		}
// 
//		if(c>=13&&c<=14){
//			int id=0;
//			for(int i=1;i<=n;++i)
//				if(abs(a[i]-a[1])<=d&&abs(a[i]-a[n])<=d){
//					id=i;break;
//				}
//			for(int i=1)
//		}
	}
	

	return(0);
}
