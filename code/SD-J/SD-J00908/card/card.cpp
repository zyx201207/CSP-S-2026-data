#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool vis[300005];
long long cnt[300005];
deque<int> q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		q.clear();
		memset(vis,0,sizeof vis);
		for(int i=k;i<=n;i++){
			if(vis[a[i]]!=0){
				while((!q.empty())&&q.back()!=a[i]){
					vis[q.back()]=0;
					q.pop_back();
				}
			}else{
				q.push_back(a[i]);
				vis[a[i]]=1;
			}
		}
		while(!q.empty()){
//			cout<<q.front()<<" ";
			cnt[q.front()]++;
			q.pop_front();
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

