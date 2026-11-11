#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int N=5e5+34,M=3e5+34;
ll n,m;
int a[N];
ll ans[M];
unordered_map<int,int> mp;
stack<int> s;

int main(){
	freopen("card.in","r",stdin);	
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp.count(a[j])==0){
				s.push(a[j]);
				mp[a[j]]=1;
			}else{
				while(s.top()!=a[i])s.pop();
				s.pop();
				s.push(a[j]);
			}
		}
		mp.clear();
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
