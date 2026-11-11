#include<bits/stdc++.h>
using namespace std;
struct jh{
	int zd,qd;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int rz[m];
	for(int i=0;i<m;i++){
		cin>>rz[i];
	}
	vector<vector<int>>s(m+2);
	vector<vector<int>>nu(m+2);
	vector<vector<int>>b(m);
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		for(int j=0;j<num;j++){
			int k;
			cin>>k;
			s[i].push_back(k);
			s[i].push_back(i);
			int mi;
			cin>>mi;
			nu[i].push_back(mi);
			if(j>0){
				b[s[i][j-1]].push_back(k);
				b[s[i][j-1]].push_back(i);
			}
		}
	}
	jh rw[q];
	for(int i=0;i<q;i++){
		cin>>rw[i].qd>>rw[i].zd;
	}
	for(int i=0;i<q;i++){
		long long ans=0;
		ans+=rz[rw[i].qd];
		ans+=rz[rw[i].zd];
		cout<<ans*2<<'\n';
	}
}
