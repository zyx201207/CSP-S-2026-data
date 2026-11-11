#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+20;
ll vis[N],card[N];
ll la[N];
ll n,m;
stack <ll> q;
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++) {
		cin>>card[n-i+1];
	}          //n-i+1
	for(int i=1;i<=n;i++){
	if(la[card[i]]){
		while(q.top()!=card[i]){
			la[q.top()]--;
			q.pop();
	}
			la[q.top()]--;
			q.pop();
		}
			q.push(card[i]);
			la[card[i]]++;
		
		if(1){
		stack <ll>s;
			while(!q.empty()){
				
				vis[q.top()]++;
				s.push(q.top());
				q.pop();}
			while(!s.empty()){
				q.push(s.top());
				//cout<<s.top()<<" ";
				s.pop();
			}
			
		}
	//	cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}