#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,f,a[N],vis[M],ans[M];
map<int,int>mp;
void play(int x){
	f=0;
	deque<int>q;
	for(int i=x;i<=n;i++){
		if(mp[a[i]]){
			while(!q.empty()&&q.back()!=a[i]){
				mp[q.back()]=0;
				q.pop_back();
			}
		}else q.push_back(a[i]);
		mp[a[i]]=1;
	}
	for(int i=1;i<=m;i++) if(mp[i]) ans[i]++,mp[i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		play(i);
	}
	for(int i=1;i<=m;i++){
		if(i>1) cout<<" ";
		cout<<ans[i];
	}
	return 0;
}
