#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int BIT=31;
int n,m;
vector<int> a;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	int ans=0;
	for(int i=BIT-1;i>=0;i--){
		vector<int>b;
		for(auto j:a) {
			if((j>>i)&1) b.push_back(j);
		}
		if(b.size()>=m) a=b,ans|=(1<<i);
	}
	cout<<ans<<endl;
}
