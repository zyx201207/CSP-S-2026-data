#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> ans(m+1,0);
	for(int i=1;i<=n;i++){
		stack<int> s;
		vector<bool> b(m+1,0);
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(s.top()!=a[j]){
					b[s.top()]=false;
					s.pop();
				}
			}else{
				s.push(a[j]);
				b[a[j]]=true;
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

