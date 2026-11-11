#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,p,w[N],t=0;
long long res=1;
vector<vector<pair<int,int> > >r(N),s(N);

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<2*k;j++){
			int a,tt;
			cin>>a>>tt;
			t=tt;
			r[i].push_back({a,0});
			s[a].push_back({i,0});
		}
	}
	while(p--){
		int be,en;
		cin>>be>>en;
		long long ans=0;
		ans+=w[be]+w[en];
		vector<int>v(m+10);
		ans+=res*t;
		cout<<ans<<' ';
	}
	return 0;
} 
