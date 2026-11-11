#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
ll c,num[N],n,m,d,q,ans=INT_MAX,w[N],k[N],a[N][N],t[N][N],st[N],en[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];//口到厅
	for(int i=1;i<=n;i++){
		cin>>k[i];//个数
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];//i->线路 j->第几个 //几号站台
			cin>>t[i][a[i][j]];//i->线路 a[i][j]->几号站台 //厅到台
		}
	}
	for(int i=1;i<=q;i++) cin>>st[i]>>en[i];
	for(int i=1;i<=q;i++){
		num[i]+=(w[st[i]]+w[en[i]]);
		for(int j=1;j<=n;i++){
			if(t[j][st[i]]>0){
				ans=num[i]+t[j][st[i]]+t[j][en[i]];
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
