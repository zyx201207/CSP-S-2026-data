#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+5;//nerfed
int n;ll d;
ll x[N];
int dis[N];

void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	
	ll ans=0;
	for(int i=1;i<n;i++){
		int l=i,r=i+1;
		deque<pair<int,pair<int,int>>> q;//dis,maxmark,cnt
		q.push_back({0,{0,1}});dis[i]=0;
		for(;r<=n;r++){
			while(l<r&&x[r]-x[l]>d){
				if(q.front().first==dis[l]){
					q.front()={q.front().first,{q.front().second.first,q.front().second.second-1}};
					if(q.front().second.second<=0)q.pop_front();
				}
				l++;
			}
			if(l==r)break;
			
			int md=q.front().first,mm=q.front().second.first,mc=q.front().second.second;
			dis[r]=md+1;
			int mark;
			if(mm==0)mark=(mc==1?0:(mc==2?1:2));
			else if(mm==1)mark=(mc==1?1:2);
			else mark=2;
			if(mark==1)ans++;
			
			while(!q.empty()&&q.back().first>dis[r])q.pop_back();
			if(!q.empty()&&q.back().first==dis[r]){
				q.back()={q.back().first,{max(q.back().second.first,mark),q.back().second.second+1}};
			}else{
				q.push_back({dis[r],{mark,1}});
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	
	int c,T;cin>>c>>T;
	while(T--)Solve();
	
	cout<<flush;
	return 0;
}
