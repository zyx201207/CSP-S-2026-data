#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int n,size,a[N],m,flag=1,ans[N],maxx,vis[N],b[N];
signed main(){
	IOS
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i!=1){
			flag=0;
		}
	}
	
	if(flag){
		int last=1;
		for(int i=1;i<=m;i++){
			int k=upper_bound(a+1,a+1+n,i)-a-1;
			if(a[k]==i){
				ans[i]=k-last+1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}else{
		queue<int> q;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				q.push(a[j]);
				memset(b,0,sizeof(b));
				memset(vis,0,sizeof(vis));
				int l=1,shu;
				while(q.size()){
					int t=q.front();
					q.pop();
					b[l++]=t;
				}
				for(int p=1;p<l;p++){
					vis[b[p]]++;
				}
				for(int p=1;p<=m;p++){
					
					if(vis[p]==2){
						shu=p;
						break;
					}
					
				}
				
				int yi=0,er=0;
				for(int p=1;p<l;p++){
					if(b[p]==shu&&yi==0){
						yi=p;
					}else if(b[p]==shu){
						er=p;
						break;
					}
				}
				for(int p=1;p<l;p++){
					if(yi<=p&&p<er){
						continue;
					}
					q.push(b[p]);
				}
			}
			while(q.size()){
				int t=q.front();
				q.pop();
				ans[t]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
