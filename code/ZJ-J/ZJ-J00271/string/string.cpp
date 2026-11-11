#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	long long nm;
	char ch;
};
deque <node> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		long long nmi;char chi;
		cin>>nmi>>chi;
		q.push_back({nmi,chi});
	}
	while(q.size()>1){
		node u=q.front(),v=q.back();q.pop_front();q.pop_back();
		if(u.nm>v.nm){
			u.nm-=v.nm;
			q.push_front(u);
			if(u.ch!=v.ch)ans+=v.nm;
		}else {
			v.nm-=u.nm;
			q.push_back(v);
			if(u.ch!=v.ch)ans+=u.nm;
		}
	}
	cout<<ans;
}