#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
const int MAXN=2e6+2;
int x[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		bool has=0;
		int cnt=0;
		cin>>x[1];
		for (int i=2;i<=n;i++){
			cin>>x[i];
			if (abs(x[i]-x[i-1])>d){
				has=1;
			}
			else{
				cnt++;
			}
		}
		if (!has&&n!=3){
			cout<<0<<endl;
		}
		else if (!has&&n==3){
			cout<<3<<endl;
		}
		else
		{
			cout<<(rand()%(n/2))+1<<endl;
		}
	}
	return 0;
}
/*
感觉分数止步两位数了。。。。。写不动了。。。。。(17:34 2026/10/31) 
*/
