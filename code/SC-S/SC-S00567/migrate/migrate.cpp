#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main (){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		vector<pair<long long,long long> >vec;
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int l=1;l<=n;l++){
			long long r=l+3;
			if(r>n)continue;
//			cout<<a[r]<<" "<<a[l]<<endl;
			if(a[r]-a[l]<=d)continue;
			if(a[r]-a[l+1]>d)continue;
			if(a[r-1]-a[l]>d)continue;
//			cout<<l<<" "<<r<<endl;
			vec.push_back({r,l});
		}
		long long opp=vec.size();
		long long ans=0;
		for(int i=0;i<opp;i++){
			long long ll=vec[i].second;
			long long rr=vec[i].first;
			long long lll;
			long long rrr;
			if(i==0){
				lll=1;
			}else{
				lll=vec[i-1].second;
			}
			if(i==opp-1){
				rrr=n;
			}else{
				rrr=vec[i+1].first;
			}
		for(int j=rrr;j<rr;j++){
			if(a[j+1]-a[j]<=d){
				ans++;
			}else{
				break;
			}
		}
			for(int j=ll;j<lll;j++){
				if(a[j+1]-a[j]<=d){
					ans++;
				}else{
					break;
				}
			}
			ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}