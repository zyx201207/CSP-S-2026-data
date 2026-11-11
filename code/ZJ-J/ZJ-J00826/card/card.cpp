#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1000005],ans[10000005];
deque<ll> q;
bool vis[10000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	//code
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll point=a[i];
		bool flag=false;
		ll sizer=q.size();
		for(int j=0;j<sizer;j++){
			if(q.front()==point){
				flag=true;
			}
			if(flag==false) q.push_back(q.front());
			q.pop_front();
		}
		q.push_back(point);
		memset(vis,false,sizeof(vis));
		sizer=q.size();
		for(int j=1;j<=m;j++){
			if(vis[q.front()]==false) ans[q.front()]++;
			vis[q.front()]=true;
			q.push_back(q.front());
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
