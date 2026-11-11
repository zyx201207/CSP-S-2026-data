#include <bits/stdc++.h>
using namespace std;
const int e=2e4+5;
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1);
	vector<vector<long long>>T(m+1,vector<long long>(1)),B(m+1,vector<long long>(1)),N(n+1,vector<long long>(n+1,-1));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=n;j++){
			int a,t;cin>>a>>t;
			B[a].push_back(i);
			T[i].push_back(t);
		}
	}
	for(int i=1;i<=n;i++){
		if(B[i].size()>1){
			int l=B[i].size();
			for(int a=1;a<=l;a++){
				for(int b=a+1;b<=l;b++){
					N[B[i][a]][B[i][b]]=T[B[i][a]][i]+T[B[i][b]][i];
					N[B[i][b]][B[i][a]]=T[B[i][a]][i]+T[B[i][b]][i];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		long long ans=w[l]+w[r],s=1e18;
		bool f=0;
		for(int a=1;a<=(int)B[l].size();a++){
			for(int b=1;b<=(int)B[r].size();b++){
				if(B[l][a]==B[r][b]){f=1,ans+=T[B[l][a]][l]+T[B[l][a]][r];}
				if(N[B[l][a]][B[r][b]])s=min(s,N[B[l][a]][B[r][b]]+T[B[l][a]][l]+T[B[r][b]][r]);
			}
		}
		if(f){cout<<ans<<'\n';continue;}
		cout<<ans+s<<'\n';
	}
	return 0;
}