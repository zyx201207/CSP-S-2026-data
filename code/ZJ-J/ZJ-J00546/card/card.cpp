#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map<int,int> mp;
bool ffind(stack<int> x,int a){
	while(!x.empty()){
		if(a==x.top()){
			return true;
		}else{
			x.pop();
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(s.empty()){
				s.push(a[j]);
				continue;
			}
			if(ffind(s,a[j])==0){
				s.push(a[j]);
			}else{
				while(s.top()!=a[j]){
					s.pop();
				}
			}
		}
		while(!s.empty()){
			mp[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}

