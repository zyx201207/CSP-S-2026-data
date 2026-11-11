#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N=2e5+5;
ll n,ans;
pair<ll,char>a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	pair<ll,char>x1={0,0};
	pair<ll,char>x2={0,0};
	int l=1,r=n;
	while(l<=r){
		if(x1.first==0){
			x1=a[l++];
		}if(x2.first==0){
			x2=a[r--];
		}
		int minn=min(x1.first,x2.first);
		x1.first-=minn;x2.first-=minn;
		if(x1.second!=x2.second){
			ans+=minn;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
