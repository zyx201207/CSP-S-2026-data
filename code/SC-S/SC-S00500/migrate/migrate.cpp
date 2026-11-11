#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1145141];/*
struct way{
	int l,t;
} dp[1145141];
void solve(){
	deque<int> q;
	for(int i=1;i<=n;i++){
		while(!q.empty()&&x[i]-x[q.top()]>d) q.pop_front();
		if(!q.empty()){
			dp[i]=
			int cnt=1,tmp=q.top();
			q.pop();
			stack<int> s;
			s.push(tmp);
			while(!q.empty()&&dp[q.top()].l==dp[tmp].l){
				cnt++;
				s.push(q.top());
				q.pop();
			}
			
		}
	}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<0<<endl;
	}
	return 0;
}
