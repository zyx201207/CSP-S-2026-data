#include <bits/stdc++.h>
using namespace std;
int n,m,idx;
bool f[300010];
int a[500010],cnt[300010];
stack<int> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		while(!s.empty()){
			s.pop();
		}
		for(int i=t;i<=n;i++){
			if(f[a[i]]){
				while(s.top()!=a[i]){
					f[s.top()]=false;
					s.pop();
				}
			}
			else{
				s.push(a[i]);
				f[a[i]]=true;
			}
		}
		while(!s.empty()){
			f[s.top()]=false;
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}