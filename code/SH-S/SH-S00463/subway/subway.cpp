#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5;
long long c,n,m,d,q,w[N],x,cnt=2;
vector<int> t[N];
int main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	int y=1;
	while(n--){
		int a,b;
		cin >> a;
		for(int i = 1;i<=a;i++){
			cin >> b;
			t[y].push_back(b); 
			cin >> x;
		}
		y++;
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		long long ans = 0;
		ans+=w[l]+w[r];
		for(int i = 1;i<n;i++){
			for(int j = 1;j<=t[i].size();j++){
				for(int k = 1;k<=t[i+1].size();k++){
					if(t[i][j] == t[i+1][k]) cnt++;	
				}
			}
		}
		cout << cnt*x+ans << endl;
	}
	return 0;
}

