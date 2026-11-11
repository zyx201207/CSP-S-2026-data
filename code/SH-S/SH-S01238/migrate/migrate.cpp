#include<bits/stdc++.h>

using namespace std;

ifstream fin("migrate.in");
ofstream fout("migrate.out");
#define cin fin
#define cout fout
#define endl '\n'

using ll=long long;
const int N=2e6+9;
const int inf=1e9;

ll p[N],d,ans;
int lfa[N],rfa[N],n;

inline void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>p[i];
	
	for(int i=1,j=1;i<=n;i++){
		while(p[i]-p[j]>d) j++;
		lfa[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(p[j]-p[i]>d) j--;
		rfa[i]=j;
	}

	for(int i=1;i<=n;i++){
		int x=i;
		vector<int> t(n+1,0);
		while(lfa[x]!=x){
			for(int i=0;i<x-lfa[x];i++) t[lfa[x]+i]=min(i,2);
			x=lfa[x];
		}
		vector<int> s(n+1,0);
		for(int j=i;j>=x;j--){
			s[j]=s[rfa[j]]+t[rfa[j]];
			if(s[j]==1) ans++;
		}
	}

	cout<<ans<<endl;

	ans=0;
	for(int i=1;i<=n;i++) lfa[i]=rfa[i]=0;
}

signed main(){
	int c,T;
	cin>>c>>T;
	while(T--) Solve();

	return 0;
}