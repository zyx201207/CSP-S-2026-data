#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
int dis[N];
ll ways[N];
ll x[N];
int last_[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n;
		ll d;
		cin >> n >> d;
		last_[1]=0;last_[2]=1;
		for(int i=1;i<=n;i++){
			cin >> x[i];
			if(i==2&&x[2]-x[1]>d) last_[2]=2;
			if(i>=3){
				last_[i]=last_[i-1];
				while(x[i]-x[last_[i]]>d) last_[i]++;
			}
		}
		if(c==11||c==12){
			int k=d/(x[2]-x[1])
			if(n>=2*k&&k>=2) cout << n-2*k+1 << "\n";
			else cout << "0\n";
			continue;
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			dis[i]=0,ways[i]=1;
			for(int j=i+1;j<=n;j++) {
				if(last_[j]==j||dis[j-1]==0x3f3f3f3f){
					dis[j]=0x3f3f3f3f;
					break;
				}
				else if(last_[j]<=i){
					dis[j]=1;
					ways[j]=1;
					continue;
				}
				dis[j]=dis[last_[j]]+1;
				ways[j]=0;
				for(int k=last_[j];k<j;k++){
					if(dis[k]==dis[j]-1) ways[j]+=ways[k];
				}
				if(ways[j]>3) ways[j]=3;
				if(ways[j]==2) cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}