#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
queue<pair<ll,char> > que;
stack<pair<ll,char> > st;
pair<ll,char> b;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		pair<ll,char> a;
		cin>>a.first>>a.second;
		que.push(a);
		st.push(a);
	}
	b=que.front();
	que.pop();
	
	while(!st.empty()){
		pair<ll,char> a=st.top();
		st.pop();
		while(a.first!=0) {
			ll kiso=min(a.first,b.first);
			a.first-=kiso;
			b.first-=kiso;
			if(a.second!=b.second){
				ans+=kiso;
			}
			if(b.first==0){
				b=que.front();
				que.pop();
			}
		}
	
	}
	cout<<ans/2;
	
	return 0;
} 
