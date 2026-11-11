#include<bits/stdc++.h>
#define int long long
#define go(x)(cout<<x<<'\n',void())
#define go1(x)(cout<<x<<' ',void())
#define go2(x)(cout<<x,void())
#define in(x)(cin>>x,void())
#define in1(x,y)(cin>>x>>y,void())
#define in2(x,y,z)(cin>>x>>y>>z,void())
#define in3(x,a,s,c,d)(cin>>x>>a>>s>>c>>d,void())
#define vi vector<int>
#define vc vector<char>
#define ve vector 
#define pb push_back
using namespace std;
struct node1{
	int line;
	vi station,costinstation;
};
int c,n,m,d,q;
void solve(){
	in3(c,n,m,d,q);
	static vi cost_koutoting(m);
	static vector<string> tong()
	node1 all_line[n];
	for(int i=0;i<m;i++) cin>>cost_koutoting[i];
	for(int i=0;i<n;i++){
		int k;
		in (k);
		all_line[i].line=i;
		for(int j=0;j<k;j++) {
			int qqqq,wwww;
			in1(qqqq,wwww);
			all_line[i].station.pb(qqqq);
			all_line[i].costinstation.pb(wwww);
		}
		
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}





































//priority
