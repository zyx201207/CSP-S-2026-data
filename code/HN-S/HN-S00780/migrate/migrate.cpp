#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+50;
int c,t,n,d,ans,a[N],v[N];
//vector<int>e[N];
//void dfs(int x,int y,int cnt){
//	if(x==y){
//		if(cnt<ans){
//			c=1;
//			ans=cnt;
//		}
//		if(cnt==ans)c++;
//		return ;
//	}
//	for(auto i:e[x]){
//		if(!v[i]){
//			v[i]=1;
//			dfs(i,y,cnt+1);
//			v[i]=0;
//		}
//	}
//}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int o=0;
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//			e[a[i]].clear();
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(a[j]-a[i]<=d){
//					e[a[j]].push_back(a[i]);
//					e[a[i]].push_back(a[j]);
//				}else break;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=n;j>=1;j--){
//				if(a[j]-a[i]<=d)break;
//				ans=1e9;
//				c=0;
//				v[i]=1;
//				dfs(i,j,0);
//				if(c==2)o+=2;
//			}
//		}
		cout<<o<<"\n";
	}
	
	return 0;
}
