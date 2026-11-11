#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int _,n,m,k,a[N],vi[101],si[101];
vector<int> ve[N];
void bf(int st){
	queue<int> q;
	q.push(st);
	vi[st]=0;
	while(q.size()){
		int as=q.front();
		q.pop();
		for(int x:ve[as]){
			if(vi[x]){
				vi[x]=0;
				q.push(x);
			}
		}
	}
}
int an(){
	int ans=1;
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(si[i]){
			q.push(i);
		}
	}
	while(q.size()){
		int as=q.front();
		q.pop();
		for(int x:ve[as]){
			if(si[x]==0){
				si[x]=si[as]+1;
				ans=max(ans,si[x]);
				q.push(x);
			}
		}
	}
	return ans-1;
}
int main(){
	freopen("hub.in","r", stdin);
	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
//	freopen("hub.in","r", stdin);
//	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);//cout.tie(0);
	cin>>_>>_;
	while(_--){
		int ans=999999;
		cin>>n>>k;
		for(int i = 1,u,v;i<n;i++){
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		for(int i = 1;i<(1<<k);i++){
			for(int j = 1;j<=n;j++)vi[j]=si[j]=0;
			int now=0;
			for(int j = 0;j<k;j++){
				if((i>>j)&1){
					vi[j+1]=1;
					si[j+1]=1;
					now++;
					if(now>k)break;
				}
			}
			if(now!=k)continue;
			int cnt=0;
			for(int j = 1;j<=n;j++){
				if(vi[j]){
					bf(j);
					cnt++;
				}
				if(cnt>2)break;
			}
			if(cnt>2)continue;
			ans=min(ans,an());
		}
		cout<<ans<<"\n";
	}
}

