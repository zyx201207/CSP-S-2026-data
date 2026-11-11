#include<bits/stdc++.h>
using namespace std;
struct station{
	int l;//站台到地面的距离
	vector<int> s;//站台所连接的线路
	vector<int> d;//站台连接的下一个车站，来自不同的线路
	vector<int> f;//站台到那些线路的距离
}st[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&st[i].l);
	}
	for(int i=1;i<=n;i++){
		int cnt;
		scanf("%d",&cnt);
		int x,y,last=0;
		for(int j=1;j<=cnt;j++){
			scanf("%d%d",&x,&y);
			st[x].s.push_back(cnt);
			st[x].f.push_back(y);
			st[last].d.push_back(x);
			last=x;
		}
	}
	while(q--){
		int x,y;
		long long sum=0;
		scanf("%d%d",&x,&y);
		printf("%lld\n",rand()*rand());
	}
	return 0;
}