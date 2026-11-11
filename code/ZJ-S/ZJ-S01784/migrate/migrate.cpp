#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d,x[N],wt[N],pr[N],dd[N],f[N],cnt[N],ans;

priority_queue<pair<int,int> >q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			wt[i]=(upper_bound(x+1+i,x+1+n,x[i]+d)-x-1);
			pr[i]=(lower_bound(x+1,x+i,x[i]-d)-x);
//			cout<<wt[i]<<" "<<pr[i]<<"\n";
		}
		for(int i=1;i<=n;i++){
//			r=wt[i],c=1;
//			for(int j=i+1;j<=n;j++){
//				if(j>r&&wt[r]==r)break;
//				if(j>r){
//					wt[r]=r;
//					c++;
//				}
//				
//			}
			for(int j=1;j<=n;j++){
				if(j!=i)dd[j]=1e18;
				f[j]=cnt[j]=0;
			}
			dd[i]=0;
			while(!q.empty()){
				q.pop();
			}
			q.push({-0,i});
//			cout<<i<<"\n\n\n";
			while(!q.empty()){
				int wtx=q.top().second,wtt=q.top().first;
//				cout<<wtx<<"\n";
				q.pop(); 
//				if(f[wtx])continue;
//				f[wtx]=1;
				for(int j=wtx+1;j<=wt[wtx];j++){
//					if(j==wtx)continue;
					if(dd[wtx]+1>dd[j])continue;
					if(dd[wtx]+1==dd[j])cnt[j]++;
					dd[j]=dd[wtx]+1;
//					cnt[j]=0;
					q.push({-dd[j],j});
					
				}
			}
			for(int j=1;j<=n;j++){
//				cout<<j<<" "<<dd[j]<<" "<<cnt[j]<<"\n";
				if(cnt[j]==1)ans++;
			}
			
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
