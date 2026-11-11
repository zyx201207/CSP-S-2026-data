#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500&&m<=200){
		ll b[N]={0};
		for(int i=1;i<=n;i++){
			set<int> g;
			stack<int> q;
			for(int j=i;j<=n;j++){
				if(g.count(a[j])){
					while(!q.empty()){
						int e=q.top();
						q.pop();
						g.erase(e);
						if(e==a[j]) break;
					}
					q.push(a[j]);
				}
			}
			while(!q.empty()){
				int e=q.top();
				q.pop();
				b[e]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}else if(n<=5000&&m<=3000){
		map<int,int> mp;
		for(int i=1;i<=n;i++){
			mp[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			cout<<mp[i]<<" ";
		}
	}
	return 0;
}
