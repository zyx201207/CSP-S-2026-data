#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,a[N];
vector<ll>v;
stack<ll>st;
map<ll,bool>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i){ //点数为i的牌 
		ll cnt=0;
		for(int j=1;j<=n;++j){  //第j局 
			for(int k=j;k<=n;++k){  // 枚举出牌数量+下标 
				if(st.empty()){
					st.push(a[k]);
					mp[a[k]]=1;
					continue;
				} 
				else{
					if(mp[a[k]]){
						while(!st.empty()){
							ll p=st.top();
							st.pop();
							if(p==a[k]){
								break;
							}
						}
						st.push(a[k]);
					}
					else{
						st.push(a[k]);
						mp[a[k]]=1;
					}
				}
			}
			while(!st.empty()){
				ll op=st.top();
				st.pop();
				if(op==i){
					cnt++;
				}
				v.push_back(op);
			}
			for(int l=0;l<v.size();++l){
				if(v[l]==0) continue;
				st.push(v[l]);
				v[l]=0;
			}
		}
		while(!st.empty()){
			st.pop();
		}
		cout<<cnt<<' ';
	}
	return 0;
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
}
