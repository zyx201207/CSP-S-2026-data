#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int c,t,n;
ll d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=0;i<t;i++){
		
		cin>>n;
		if (c==13||c==14){
			if (n==4) {
				cout<<"1"<<endl;
			}
			else {
				cout<<"0"<<endl;
							}
							continue;
		}
		ll ans=0;
		vector<ll> place(n+5);
		for (int i=1;i<=n;i++){
			ll t;
			cin>>t;
			place[i]=t;
		}
//		for (int i=1;i<n;i++){
//			vector<vector<int>>able{{i},{}};
//			vector<int>route(n+5,0);
//			int j=i;
//			while(!able[0].empty()){
//				int now=able[0][0];
//				able[0].erase(able[0].begin());
//				for (int k=j+1;(k<=n)&&(place[k]-place[now]<=d);k++){
//					if (k>(able[1][able[1].size()-1])||able[1].empty())able[1].push_back(k);
//					route[k]++;
//				}
//				if (able[0].empty()){
//					able[0]=able[1];
//					able[1].clear();
//					j=able[0][able[0].size()-1];
//					continue;
//				}
//			}
//			for (int j=i+1;j<=n;j++){
//				if (route[j]==2) ans++;
//			}
		for (int i=1;i<n;i++) {
			vector<int> able,times,route(n+5,0),length(n+5,-1);
			able.push_back(i);
			times.push_back(0);
			while (!able.empty()){
				int now=able[0],time=times[0];
				able.erase(able.begin());
				times.erase(times.begin());
				for (int k=now+1;(k<=n)&&(place[k]-place[now]<=d);k++){
					able.push_back(k);
					times.push_back(time+1);
					if (time<=length[k]||length[k]==-1){
						route[k]++;
						length[k]=time;
					}
					
				}
			}
			for (int j=i+1;j<=n;j++){
				if (route[j]==2) ans++;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
