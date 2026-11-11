#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,ans,K;
struct node{
	int num;char id;
};
deque<node> dq;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		char a;
		cin>>x>>a;
		K+=(x%2);K=K%2;
		dq.push_back({x,a});
	}
		while(dq.size()>K){
			node i=dq.front(),j=dq.back();
			int mn=min(i.num,j.num);
			dq.pop_front(),dq.pop_back();
			if(i.id!=j.id)ans+=mn;
				if(i.num>j.num){
					dq.push_front({i.num-mn,i.id});
				}
				else{
					dq.push_back({j.num-mn,j.id});
				}
		}
	cout<<ans<<endl;
	return 0;
}
