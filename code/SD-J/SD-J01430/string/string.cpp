#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long LL;
LL n,x,l,r,sum;
LL ans;
vector<pair<char,int>> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char s;
		cin>>x>>s;
		q.push_back({s,x});
		sum++;
	}
	l=0;
	r=n-1;
	while(sum>1&&l<r){
		if(q[l].first!=q[r].first){
			ans+=min(q[l].second,q[r].second);
		}
		LL wnm=min(q[l].second,q[r].second);
		q[l].second-=wnm;
		q[r].second-=wnm;
		if(q[l].second==0) sum--,l++;
		if(q[r].second==0) sum--,r--;
	}
	cout<<ans<<endl;
	return 0;
}
