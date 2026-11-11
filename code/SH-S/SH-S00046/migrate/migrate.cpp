#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[5010],cnt[5010],nxt[5010],cf[5010],ans;
bool book[5010];
void bfs(int st){
//	cout<<st<<"\n";
	for (int i = 1; i <= n; i++) cf[i]=0x3f3f3f3f,cnt[i]=0;
	cf[st]=0;
	cnt[st]=1;
	for (int i = st; i <= n; i++){
		for (int j = i+1; j <= nxt[i]; j++){
			if (cf[j]>cf[i]+1){
				cnt[j]=cnt[i];
			}
			if (cf[j]==cf[i]+1){
				cnt[j]+=cnt[i];
				if (cnt[j]>2) cnt[j]=3;
			}
			cf[j]=min(cf[j],cf[i]+1);
		}
//		for (int i = 1; i <= n; i++){
//			cout<<cnt[i]<<" "<<cf[i]<<"\n";
//		}
//		cout<<"&&&\n";
	}
	for (int i = 1; i <= n; i++){
//		cout<<cnt[i]<<" "<<cf[i]<<"\n";
		if (cnt[i]==2){
			ans++;
		}
	}
//	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//cout<<LONG_LONG_MAX;
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		ans=0;
		for (int i = 1; i <= n; i++){
			cin>>x[i];
		}
		for (int i = 1; i <= n; i++){
			nxt[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		}
		for (int i = 1; i <= n; i++){
			bfs(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
一种贪心策略：每次跑最右侧的、相差不超过p的点 
6 3
0 1 2 3 4 7
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
0 1
8 3
0 1 2 4 8 10 11 13

*/
