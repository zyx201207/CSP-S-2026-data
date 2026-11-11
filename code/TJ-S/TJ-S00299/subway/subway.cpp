#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,n,m,d,q;
ll w[500006];
ll mp[9999][9999];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			mp[i][j] = INT_MAX;
		}
	}
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 0;i<n;i++){
		int k;
		cin >> k;
		int a1 = 0,a2 = 0,v = 0;
		for(int j = 0;j<k;j++){
			cin >> a1 >> v;
			if(a2!=0){
				mp[a1][a2] = mp[a2][a1] = v;
			}
			else{
				mp[a1][a1] = v;
			}
			a2 = a1;
		}
	}
	for(int z = 1;z<=m;z++){
		for(int i = 1;i<z;i++){
			for(int j = z;j<=m;j++){
				if(i!=j) mp[i][j] = min(mp[i][j],mp[i][z]+mp[z][j]+w[z])+w[i]+w[j];
			}
		}
	}
	int s,e;
	for(int i = 0;i<q;i++){
		cin >> s >> e;
		cout << mp[s][e] << endl;
	}
	return 0;
} 
