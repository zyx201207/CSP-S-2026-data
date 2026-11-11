#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define ll long long
using namespace std;
ll n,m,a[500005],f[500005],cnt[500005],s[500005];
deque<ll> q;
map<ll,ll> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) mp[j]=0,s[j]=0;
		for(int j=i;j<=n;j++){
			ll da=a[j];
			if(mp[da]!=0){
				for(int k=1;k<=q.size()-mp[da]+1;k++) q.pop_back();
			}
			q.push_back(da);
			mp[da]=q.size();
		}
		while(!q.empty()){
			s[q.front()]++;
			if(s[q.front()]==1) cnt[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
