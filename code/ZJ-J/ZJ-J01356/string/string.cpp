#include<bits/stdc++.h>
using namespace std;
using LL=long long;
//#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define endl '\n'
int n;
struct node{
	LL len;
	char c;
};
queue<node>q;
stack<node>t;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		node z;
		cin>>z.len>>z.c;
		q.push(z);
		t.push(z);
	}
	LL ans=0;
	node l=q.front(),r=t.top();
	q.pop();
	t.pop();
	while(1){
		if(l.c!=r.c)ans+=min(l.len,r.len);
		if(q.empty() && t.empty())break;
		if(l.len>=r.len){
			l.len-=r.len;
			if(!t.empty()){
				r=t.top();
				t.pop();
			}
		}else{
			r.len-=l.len;
			if(!q.empty()){
				l=q.front();
				q.pop();
			}
		}
	}
	cout<<ans/2;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
