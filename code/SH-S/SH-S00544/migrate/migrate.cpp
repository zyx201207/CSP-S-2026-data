#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int n;
			long long d,ans=0;
			cin>>n>>d;
			vector<long long> x(5010);
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<=n;i++){
				vector<int> cnt(5010,0);
				vector<int> jl(5010,INT_MAX);
				priority_queue<int,vector<int>,greater<int> > q;
				q.push(i);
				jl[i]=0;
				while(!q.empty()){
					int now=q.top();
					q.pop();
					for(int j=now+1;j<=n;j++){
						if((x[j]-x[now])<=d){
							if((jl[now]+1)<jl[j]) cnt[j]=1,q.push(j),jl[j]=jl[now]+1;
							else if((jl[now]+1)==jl[j]) cnt[j]++,q.push(j),jl[j]=jl[now]+1;
						}
						else break;
					}
				}
				for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
