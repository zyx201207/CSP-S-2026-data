#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m,a[N],cnt[N],ans[N];
queue<ll>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(!cnt[a[j]]){
				cnt[a[j]]++;
				q.push(a[j]);
			}else{
				q.push(a[j]);
				while(!q.empty()){
					if(q.front()==a[j]&&cnt[a[j]]-1==0) break;
					else q.pop();
				}
			}
		}
		while(!q.empty()){
			ll x=q.front();
			ans[x]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
