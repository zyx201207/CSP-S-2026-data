#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200005],b[200005][40];
int mb=-1e18;
bool vis[200005];

void cw(int i,int t){
	
	int cnt=0;
	while(t){
		b[i][++cnt]=t%2;
		t/=2;
		//cout<<b[i][cnt];
	}
	mb=max(mb,cnt);
	return ;
	
}

vector <int> id[40],ans;

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int maxn=-1e18;
	
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		maxn=max(maxn,a[i]);
		cw(i,a[i]);
		//cout<<'\n';
		
	}
	
	if(m==1)cout<<maxn;
	else if(m==n){
		
		int res=a[1];
		for(int i=2;i<=n;i++)res=res&a[i];
		cout<<res;
		
	}else{
		
		for(int i=1;i<=n;i++){
			for(int j=mb;j>=1;j--){
				if(b[i][j])id[j].push_back(i);
			}
		}
		
		bool ismax=true;
		for(int i=mb;i>=1;i--){
			if(id[i].size()>m)ismax=false;
			
			if(ismax&&id[i].size()==m){
				for(int j=0;j<id[i].size();j++)ans.push_back(id[i][j]);
				break;
			}
			
			if(id[i].size()<m)continue;
			
			priority_queue <pair<int,int> > pq;
			for(int j=0;j<id[i].size();j++)pq.push({a[id[i][j]],id[i][j]});
			for(int j=1;j<=m;j++){
				int t=pq.top().second;
				pq.pop();
				ans.push_back(t);
				//cout<<t<<' ';
			}
			//cout<<"µÚ"<<i<<"ÂÖ"<<'\n';
			
		}
		
		int res=-1;
		for(int i=0;i<ans.size();i++){
			//cout<<ans[i]<<' ';
			
			priority_queue <pair<int,int> > pq;
			for(int j=0;j<ans.size();j++)pq.push({a[ans[j]],ans[j]});
			ans.clear();
			int cnt=0;
			while(!pq.empty()){
				int t=pq.top().second;
				pq.pop();
				if(!vis[t])cnt++;
				vis[t]=true;
				ans.push_back(t);
				if(cnt==m)break;
				//cout<<t<<' ';
			}
			//cout<<"µÚ"<<i<<"ÂÖ"<<'\n';
			
			memset(vis,false,sizeof vis);
			if(ans[i]){
				if(res==-1)res=a[ans[i]];
				else if(!vis[ans[i]])res&=a[ans[i]],vis[ans[i]]=true;;
			}
		}
		
		if(res!=-1)cout<<res;
		else cout<<0;
		
	}
	return 0;
	
}
/*
4 2
3 15 12 12
*/
