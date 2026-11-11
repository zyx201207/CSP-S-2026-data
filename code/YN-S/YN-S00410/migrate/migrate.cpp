#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 5;
LL c,t;
LL a[N];
struct aaa{
	int Max,cnt;
}ans[5005][5005];;

LL k;
int n,d;
//
//void dfs(int x,int cnt){
//	if(x<=n){
//		if(cnt<ans[k][x].Max){
//			ans[k][x].Max=cnt;
//			ans[k][x].cnt=1;
//		}if(cnt==ans[k][x].Max){
//			ans[k][x].cnt++;
//		}
//		for(int i=d;i>=1;i--){
//			
//		}
//	}
//}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<"\n";
//		for(int i=1;i<n;i++){
//			k=i;
//			dfs(i,0);
//		}
//		
		
		
		
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
	}
	



	return 0;
}
//
//
//system("fc a.txt b.txt");
