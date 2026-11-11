#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> e[40];
bool a[200010][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		int k=32;
		while(x){
			if(x&1) a[i][k]=1;
			x/=2;
			k--;
		}
		e[2].push_back(i);
	}
	long long sf=(long long)(1<<30);
	long long ans=0;
	for(int i=2;i<=32;i++){
		int cnt=0;
		for(auto v:e[i]){
			if(a[v][i]==1){
				cnt++;
				e[i+1].push_back(v);
			}
		}
		if(cnt<m){
			for(auto v:e[i]){
				if(!a[v][i]) e[i+1].push_back(v);
			}
		}
		else ans+=sf;
		sf/=2;
	}
	cout << ans;
	return 0;
}
