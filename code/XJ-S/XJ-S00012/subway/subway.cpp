#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
struct node{
	int to,time;
}b[500][50010];
struct plan{
	int l,r;
}p[100010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		for(int j=1;j<=z;j++){
			cin>>b[i][j].to>>b[i][j].time;
		}
	}
	for(int i=1;i<=q;i++) cin>>p[i].l>>p[i].r;
	for(int i=1;i<=q;i++){
		int sum=a[p[i].l]+b[p[i].l][1].time;
		for(int j=p[i].l;j<=p[i].r;j++){
			sum+=b[j][2].time;
		}
		cout<<sum<<endl;
	}
	return 0;
}

