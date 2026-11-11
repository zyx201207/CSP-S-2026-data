#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
	cin>>c>>T;
	while(T--){
		int n,ans=0;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<int> vec;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ll k=a[i];
				vec.clear();
				vec.push_back(i);
				while(k<a[j]){
					int idx=upper_bound(a+1,a+1+n,k+d)-a;
					k=a[idx-1];
					if(idx-1<j) vec.push_back(idx-1);
				}
				bool flag=0;
				for(int t=0;t<vec.size()-2;t++){
					for(int v=vec[t];v<vec[t+2];v++){
						if(v==vec[t+1]) continue;
						if(a[v]-a[vec[t]]<=d && a[vec[t+2]]-a[v]<=d){
							flag=1;
							break;
						}
					}
					if(flag) break;
				}
				if(flag) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
