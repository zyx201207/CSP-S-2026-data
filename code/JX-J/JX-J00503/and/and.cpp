#include<iostream>
#include<vector>
#define int long long
using namespace std;

int N,M,n[200005];

bool vis[200005]={};


signed main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>N>>M;
	for(int i=1;i<=N;i++)cin>>n[i];
	int jz=(1<<30);
	vector<int> t;
	while(t.size()<M&&jz>0){
		t.clear();
		for(int i=1;i<=N;i++){
			if(n[i]&jz)t.push_back(i);
		}
		jz=(jz>>1);
	}
	while(t.size()>M&&jz>0){
		vector<int>tt;
		for(const auto&i:t){
			if(n[i]&jz)tt.push_back(i);
		}
		if(tt.size()>=M)t=tt;
		jz=(jz>>1);
	}
	int ans=-1;
	for(const auto&i:t)ans=(ans&n[i]);
	cout<<ans<<endl;

}

