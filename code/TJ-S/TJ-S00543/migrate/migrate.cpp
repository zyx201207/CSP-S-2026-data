#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[200005],dis[200005],cnt[200005],pos1,pos2,ans;
queue<int>q;
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout),
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int T=1;T<=t;T++){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			for(int j=1;j<=n;j++)
				dis[j]=2e9;
			dis[i]=0;
			q.push(i);
			while(!q.empty()){
				for(int j=1;j<=n;j++)
					if(abs(x[q.front()]-x[j])<=d&&dis[j]>=dis[q.front()]+1)
						cnt[j]++,dis[j]=dis[q.front()]+1,q.push(j);
				q.pop();
			}for(int j=1;j<=n;j++)
				ans+=cnt[j]==2;
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
