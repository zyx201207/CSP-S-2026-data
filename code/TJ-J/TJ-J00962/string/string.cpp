#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	deque<pair<int,char> > q(n);
	for(int i=0;i<n;i++){
		pair<int,char> temp;
		cin>>temp.first>>temp.second;
		q.push_back(temp);
	}
	int ans=0;
	while((int)q.size()>1){
		pair<int,char> a=q.front(),b=q.back();
		q.pop_front();
		q.pop_back();
		int len=min(a.first,b.first);
		a.first-=len;
		b.first-=len;
		if(a.second!=b.second){
			ans+=len;
		}
		if(a.first!=0){
			q.push_front(a);
		}
		if(b.first!=0){
			q.push_back(b);
		}
	}
	cout<<ans;
	return 0;
}
