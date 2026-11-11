#include<bits/stdc++.h>
using namespace std;
const int N=200010;
vector<int> g[50];
int h[50]; 
int a[N];
vector<int> l;
int vis[N];
void fj(int i){
	queue<int> q;
	int x=a[i];
	int cnt=1;
	while(x){
		if(x&1){
			g[cnt].push_back(i);
			h[cnt]++;
		}
		x/=2;
		cnt++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		fj(i);
	}
	long long ans=0;
	int p=0;
	for(int i=31;i>=1;i--){
		if(h[i]<m){
			continue;
		}
		int cnt=0;
		for(int j:g[i]){
			if(vis[j]>=p){
				cnt++;
				vis[j]++;
			}
		}
		p++;
		if(cnt>=m){
			ans+=(1<<(i-1));
		}
	}
	cout << ans;
	return 0;
}
