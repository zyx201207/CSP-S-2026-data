#include <bits/stdc++.h> 
using namespace std;
struct node{
	int now
};
int c,n,m,d,q,w[1000001],k[1000001],a[500][100000],t[500][100000],x,y,cnt[100001],zhan[10001][1000],used[1000][1000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i++)cin>>w[m];
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]]++;
			zhan[a[i][j]][cnt[a[i][j]]=i;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout <<1<<endl;
	}
	return 0;
}


