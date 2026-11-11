#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m; 
bool my_find(stack<ll>s,ll find){
	while(!s.empty()){
		if(s.top()==find){
			return 1;
		}
		s.pop();
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	vector<ll>v(n+1);
	vector<ll>cnt(m+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<=m;i++){
		cnt[i]=0;	
	}
	for(int i=1;i<=n;i++){
		stack<ll>desk;
		set<ll>ans;
		desk.push(v[i]);
		for(int j=i;j<=n;j++){
			if(!my_find(desk,v[j])){
				desk.push(v[j]);
			}
			else{
				while(desk.top()!=v[j]&&!desk.empty()){
					desk.pop();
				}
				desk.push(v[j]);
			}
		}
		while(!desk.empty()){
			ans.insert(desk.top());
			desk.pop(); 
		}
		for(auto it=ans.begin();it!=ans.end();it++){
			cnt[*it]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	return 0;
}
