#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[500005];//qqqq[500005];
signed main(){
	freopen("card3.in","r",stdin);
	freopen("card3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5005){
		for(int i=1;i<=n;i++){
			deque<int> q;
			while(q.size()){
				q.pop_front();
			}
			bool vis[10005]={0};
		//	cerr<<"\n"<<i<<":\n";
			for(int j=i;j<=n;j++){
			//	cerr<<a[j]<<' '<<vis[a[j]]<<"\n";
				if(vis[a[j]]==0)vis[a[j]]=1;
				else{
					while(q.back()!=a[j])vis[q.back()]=0,q.pop_back();
					q.pop_back();
				}
				q.push_back(a[j]);
			}
			while(!q.empty()){
				ans[q.front()]++;
				q.pop_front();
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	else if(m==1){
		cout<<n;
	}
	else{
		for(int i=1;i<=n;i++)ans[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	return 0;
}

