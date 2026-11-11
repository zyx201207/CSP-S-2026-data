#include<bits/stdc++.h>
using namespace std;
set<int> s;
stack<int> q;
int a[500000+5],b[300000+5];
int main(){
//	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s.find(a[j])==s.end()){
				q.push(a[j]);
				s.insert(a[j]);
			}
			
			else{
				while(q.top()!=a[j]){
					s.erase(q.top());
					q.pop();
				}
				s.erase(q.top());
				q.pop();
				q.push(a[j]);
				s.insert(a[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(s.find(j)!=s.end())b[j]++;
		}
		while(!q.empty())q.pop();
		s.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}//no finish!
