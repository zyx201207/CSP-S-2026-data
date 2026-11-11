#include<bits/stdc++.h>
using namespace std;

int c,t;
long long n,d,x[2000010];
int cnt[2000010];
vector<int>ve[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[i]+d>=x[j])ve[i].push_back(j);
				else break;
			}
		}
		queue<pair<int,int> >q;
		memset(cnt,10000,sizeof(cnt));
		cnt[1]=0;
		for(auto i:ve[1]){
			q.push({i,0});
		}
		while(!q.empty()){
			int now=q.front().first;
			int step=q.front().second+1;
			q.pop();
			cnt[now]=min(cnt[now],step);
			for(auto i:ve[now]){
				q.push({i,step});
			}
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			if(cnt[i]>=2)ans++;
		}
		cout<<ans<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
