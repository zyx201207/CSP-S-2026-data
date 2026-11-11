#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
vector<int> qu;
int cnt=0;
bool fl=0;
int mx=0;
int n,d;
void dfs(int l,int r,int now,int sz){
	if (fl && sz>mx){
		return ;
	}
	if (now==r){
		if (!fl){
			fl=1;
			mx=sz;
		}
		if (sz==mx){
			cnt++;
		}
		return ;
	}
	for (int i=r; i>=now+1; i--){
		if (a[i]-a[now]<=d){
			dfs(l,r,i,sz+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while (T--){
		cin>>n>>d;
		for (int i=1; i<=n; i++){
			cin>>a[i];
		}
		int ans=0;
		for (int i=1; i<=n; i++){
			for (int j=i+1; j<=n; j++){
				qu.clear();
				qu.push_back(i);
				fl=0;
				mx=0;
				cnt=0;
				dfs(i,j,i,1);
				if (cnt==2){
					ans++;	
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}