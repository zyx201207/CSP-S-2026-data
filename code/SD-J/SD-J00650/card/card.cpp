#include<bits/stdc++.h>
using namespace std;
int f[500010],cnt[500010],las[300010],ans[300010],a[500010],vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		stack <int> q;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
			//	cout<<a[j]<<" ";
				if(vis[a[j]]==0){
					vis[a[j]]=1;
					q.push(a[j]);
				}else{
					while(!q.empty()&&q.top()!=a[j]){
						vis[q.top()]=0;
						q.pop();
					}
					q.pop();
					q.push(a[j]);
					//vis[a[j]]=1;
				}
			}
			while(!q.empty()){
				//cout<<q.front()<<" ";
				ans[q.top()]++;
				vis[q.top()]=0;
				q.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else{
		f[n]=n;
		cnt[n]++;
		las[a[n]]=n;
		for(int i=n-1;i>=1;i--){
			if(las[a[i]]!=0){
				int t=las[a[i]];
				while(f[t]!=t){
					t=f[t];
				}
				f[i]=t;
				cnt[t]++;
				while(t!=n){
					cnt[t+1]--;
					t=t+1;
					while(f[t]!=t){
						t=f[t];
					}
					cnt[t]++;
				}
			}else{
				f[i]=i;
				cnt[i]++;
				int t=i;
				while(t!=n){
					cnt[t+1]--;
					t=t+1;
					while(f[t]!=t){
						t=f[t];
					}
					cnt[t]++;
				}
			}
			las[a[i]]=i;
		}
		for(int i=2;i<=n;i++){
			cnt[i]+=cnt[i-1];
		} 
		for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],cnt[i]);
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		//cout<<"\n";
	}
	return 0;
}
