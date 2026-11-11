#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5*5+10;
int w[N],a[N],qx[N],qy[N];
ll t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q,k;
	queue<int>l;
	cin >>c >> m >> n >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	while(n--){
		cin >> k;
		for(int i=1;i<=k;i++){
			cin >> a[i] >> t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin >> qx[i] >> qy[i];
	}
	if(c>=12 && c<=19){
		while(q--){
			int ans=0;
			for(int i=qx[i];i<=qy[i];i++){
				ans+=w[qx[i]]+w[qy[i]];
				ans+=2*t[i];
			}
			if(q>1)cout << ans << " ";
			else cout << ans;
		}
	}
	return 0;
} 
