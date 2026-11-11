#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],x,y,t[505][500005],a[505];
long long sum;
vector<int>tp[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i]>>t[i][j];
		}
		tp[a[1]].push_back(a[2]);
		tp[a[2]].push_back(a[1]);
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		sum+=w[x]+w[y];
		int now=x;
		while(tp[now][0]!=tp[y][1]){
			now=tp[tp[now][1]][0];
			sum+=t[now][1]+t[now][0];
		}
		cout<<sum<<endl;
	}
	return 0;
}//好玩吗