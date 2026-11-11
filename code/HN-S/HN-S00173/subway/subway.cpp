#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mm=5e5+5,mn=505;
int c,n,m,d,q;
int stop[mm],ans,f[mn][mn],t1ime=114514;

vector<int> lines[mn];

signed main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>stop[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int l,r;
			cin>>l>>r;
			if(t1ime==114514) t1ime=r;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans+=stop[x]+stop[y]+t1ime*2;
		ans+=t1ime*2;
		cout<<ans<<'\n';
	}
	return 0;
}

