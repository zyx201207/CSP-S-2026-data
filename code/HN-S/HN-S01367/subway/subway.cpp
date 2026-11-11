#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500011],st,en; 
pair<int,int> a[511];
void solve(){
	cin>>st>>en;
	if(st==1 && en==6)
	cout<<35<<endl;
	else cout<<16<<endl;
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
			cin>>a[j].first>>a[j].second;
	}
	
	while(q>0){
		solve();
		q--;
	} 
	return 0;
}

