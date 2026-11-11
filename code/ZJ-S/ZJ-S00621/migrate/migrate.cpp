#include<bits/stdc++.h>
using namespace std;
long long a[2000005],l[2000005],r[2000005];
int dis[2000005],cnt[2000005];
queue<int>q,q2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;cin>>c>>t;
	while(t--){
		int n;long long d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				if(a[i]-a[j]<=d)l[i]=j;
				else break;
			}
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d)r[i]=j;
				else break;
			}
		}
		for(int j=1;j<=n;j++)dis[j]=1e9,cnt[j]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			dis[i]=0;cnt[i]=1;q.push(i);q2.push(i);
			while(!q.empty()){
				int x=q.front();q.pop();
				for(int j=l[x];j<x;j++){
					if(cnt[j]>2)break;
					if(dis[j]>dis[x]+1){
						dis[j]=dis[x]+1;
						q.push(j);
						q2.push(j);
					}
					if(dis[j]==dis[x]+1)cnt[j]+=cnt[x];
				}
				for(int j=r[x];j>x;j--){
					if(cnt[j]>2)break;
					if(dis[j]>dis[x]+1){
						dis[j]=dis[x]+1;
						q.push(j);
						q2.push(j);
					}
					if(dis[j]==dis[x]+1)cnt[j]+=cnt[x];
				}
			}
			while(!q2.empty()){
				int j=q2.front();q2.pop();
				if(cnt[j]==2)ans++;
				dis[j]=1e9,cnt[j]=0;
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
/*
__/\__
\    /
/_  _\
  \/
*/
//maybe 100+100+48+15=263?
//Oh,it is false.48->[24,40],263->[239,255]
//maybe can also 263?
//2h eat 5 chocalates.
//T3~40 at 31/10/26 16:20