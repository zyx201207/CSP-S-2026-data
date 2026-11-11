#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000005],ans,dis[2000005],cnt[2000005];	
queue<int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(11<=c&&c<=12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			ans=0;
			for(int j=1;j<=n;j++){
				dis[j]=-1;
			}
			dis[1]=0;
			q.push(1);
			while(q.size()){
				int u=q.front();
				q.pop();
				cnt[u]++;
				for(int j=u+1;j<=n;j++){
					if(a[j]-a[u]<=d){
						if(dis[j]==-1||dis[u]+1==dis[j]){
							dis[j]=dis[u]+1;
							q.push(j);
						}
					}
					else break;
				}
			}
			for(int j=2;j<=n;j++){
				if(cnt[j]==2){
					ans+=n-j+1;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					dis[j]=-1;
					cnt[j]=0;
				}
				dis[i]=0;
				q.push(i);
				while(q.size()){
					int u=q.front();
					q.pop();
					cnt[u]++;
					for(int j=u+1;j<=n;j++){
						if(a[j]-a[u]<=d){
							if(dis[j]==-1||dis[u]+1==dis[j]){
								dis[j]=dis[u]+1;
								q.push(j);
							}
						}
						else break;
					}
				}
				for(int j=i+1;j<=n;j++){
					if(cnt[j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
