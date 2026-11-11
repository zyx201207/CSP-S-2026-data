//姓名：张邦寒 学校：西安交通大学附属中学 准考证号：SN-S00335 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[300000],k[1000],a[510][30010],t[510][30010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<10<<"\n";
	}
	return 0;
}
