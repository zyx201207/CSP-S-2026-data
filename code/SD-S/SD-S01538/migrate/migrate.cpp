#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		map<int,int>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			x[i]=abs(x[i]);
			m[x[i]]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,m[x[i]]);
		}
		cout<<ans-1<<'\n';
	}
}
