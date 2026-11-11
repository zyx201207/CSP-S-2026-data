#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+100;
int pos[N],up[N];
int n,d,dis;
int mind(int a,int b){
	int cnts=0;
	while(a<b&&up[a]!=a){
		a=up[a];
		cnts++;
	}
	if(a!=up[a]||a==n-1) return cnts;
	else return -1;
}
int diss(int a,int b,int deep,int maxdeep){
	if(deep>maxdeep) return 0;
	if(a==b) return 1;
	int cnts=0;
	for(int i=a;i<=up[a]&&i<=b;i++){
		cnts+=diss(i,b,deep+1,maxdeep);
	}
	return cnts;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C,T;
	cin >> C >> T;
	while(T--){
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> pos[i];
		}
		if(C==11||C==12){
			dis=pos[1]-pos[0];
			if(dis*2>d){
				cout << 0 << endl;
				continue;
			}
			int k=d/dis*2;
			cout << (n-k+1) << endl;
		}else if(0<=C&&C<=6){
			int i=0,j=1;
			for(;j<n;j++){
				while(pos[j]-pos[i]>d){
					up[i]=j-1;
					i++;
				}
			}
			for(;i<n;i++) up[i]=n-1;
			int ans=0;
			for(int i=0;i<n;i++){
				for(int j=i+2;j<=n;j++){
					int minn=mind(i,j);
					if(minn==-1) continue;
					else if(diss(i,j,0,minn)==2){
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
