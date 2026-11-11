#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
map<int,int> mp;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		mp[x]++;
	}
	int ans=0;
	for(auto i=mp.begin();i!=mp.end();i++) {
		int ifir=i->first;
		int k=m,aans=0;
		for(auto j=i;j!=prev(mp.begin());j--){
			int jfir=j->first,jsec=j->second;
			int c=ifir-jfir;
			if(k-c*jsec>=0) aans+=jsec,k-=c*jsec;
			else {
				aans+=k/c;
				break;
			}
//			cout<<"aans="<<ans<<"\n";
		}
//		cout<<"\n";
		ans=max(aans,ans);
	}
	cout<<ans;
	
	return 0;
}
