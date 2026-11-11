#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,ans,a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >>T;
	while(T--){
		cin >>n >>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin >>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int cnt=0,mmin=n+10;
				queue<pair<int,int> > q;
				q.push({i,0});
				while(q.size()){
					pair<int,int> t=q.front();
					q.pop();
					if(t.first==j){
						if(t.second<mmin){
							mmin=t.second;
							cnt=1;
						}
						else if(t.second==mmin){
							cnt++;
						}
					}
					for(int k=t.first+1;k<=j;k++){
						if(a[t.first]+d>=a[k]){
							q.push({k,t.second+1});
						}
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout <<ans <<'\n';
	}
	return 0;
}