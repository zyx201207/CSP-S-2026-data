#include<bits/stdc++.h>
using namespace std;
int main(){
	queue<int> q;
	string s;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	while(!q.empty()){
		if(s.find(q.front)!=s.end()){
			ans++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans<<" ";
	}
	return 0;
}
