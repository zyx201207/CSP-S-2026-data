#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'
int n,x,vis[200005],ans,m;
vector<ll> li;
string data[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>x;
		while(x){
			if (x&1) data[i]+='1';
			else data[i]+='0';
			x>>=1;
		}
		int k=data[i].size();
		for (int j=k;j<=31;j++){
			data[i]+='0';
		}
	}
	for (int i=30;i>=0;i--){
		int cnt=0;
		for (int j=1;j<=n;j++){
			if (vis[j]) continue;
			if (data[j][i]=='0'){
				li.push_back(j);
			}else{
				cnt++;
			}
		}
		if (cnt>=m){
			for(int h:li){
				vis[h]=1;
			}
			ans+=(1<<i);
		}
		li.clear();
	}
	cout<<ans;
	return 0;
} 
