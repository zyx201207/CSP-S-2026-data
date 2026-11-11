#include<bits/stdc++.h>
#define int long long
using namespace std;
//rp++++++++++++++++++++++++++++++++++++++++++
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	bool dccl=(c==11||c==12),ygqt=(c==13||c==14);
	for(;t>0;--t){
		int n,d;
		cin>>n>>d;
		if(n==1){
			cout<<"0\n";
			continue;
		}
		vector<int>x(n);
		for(int i=0;i<n;++i){
			cin>>x[i];
		}
		if(dccl){
			if(d<2*(x[1]-x[0])){
				cout<<"0\n";
				continue;
			}
			int gap=d/(x[1]-x[0])*2-1;
			cout<<max(n-gap,0ll)<<"\n";
		}else if(ygqt||true){
			int mid=0,ans=0;
			for(;mid<n-1;++mid){
				if(x[n-1]-x[mid]<=d&&x[mid]-x[0]<=d){
					break;
				}
			}
			for(int i=0,it=0;i<mid;++i){
			//	int it=upper_bound(x.begin(),x.end(),x[i]+d)-x.begin();
				while(it<n&&x[i]+d>=x[it])++it;
				if(it==mid+2){
					ans+=n-it;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}