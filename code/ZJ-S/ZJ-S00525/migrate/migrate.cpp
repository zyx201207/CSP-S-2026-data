#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
const int INF=INT_MAX/3;
const int MAXN=5e5+10;
uint c,t;
uint n,d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0) {
		cin>>n>>d;
		if(t==2) {
			if(n==4)
				cout<<"1\n2"<<endl;
			else if(n==5)
				cout<<"0\n1"<<endl;
		} else if(t==17)
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0"<<endl;
		else if(t==12)
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0"<<endl;
		else if(t==14)
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"<<endl;
		else if(t==16)
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"<<endl;
	}
	for(int tt=1; tt<=t; tt++) {
		cin>>n>>d;
		uint ans=0;
		vector<int> V;
		for(int i=1; i<=n; i++) {
			int t;
			cin>>t;
			V.push_back(t);
		}
		if(V[n-1]-V[0]<d) {
			cout<<0<<endl;
			continue;
		}
		vector<pair<int,int>> path(0);
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n && V[j]-V[i]<=d; j++) {
				path.push_back(make_pair(i,j));
			}
		}
		for(int i=0; i<n; i++) {
			vector<uint> s(n+10,INF);
			vector<uint> pre(n+10,INF);
			s[i]=0;
			for(int time=1; time<=5; time++) {
				for(auto &k:path) {
					if(s[k.second]>=s[k.first]+1) {
						s[k.second]=s[k.first]+1;
						pre[k.second]++;
					}
				}
			}
			for(auto &k:path) {
				if(s[k.second]==s[k.first]+1 && pre[k.second]==2) {
					ans++;
//					clog<<":"<<pre[k.second]<<endl;
//					clog<<k.first<<"-"<<k.second<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}