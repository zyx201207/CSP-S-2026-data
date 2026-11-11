#include<bits/stdc++.h>
using namespace std;
vector<int>a,ans;
int n,m;
stack<int>s;
set<int>t;
void pop_to(int x){
	while(s.top()!=x){
		t.erase(s.top());
		s.pop();
	}t.erase(s.top());
	s.pop();
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ans.resize(m+1);
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		t.clear();
		for(int j=i;j<n;j++){
			if(t.count(a[j]))pop_to(a[j]);
			s.push(a[j]);
			t.insert(a[j]);
		}while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
