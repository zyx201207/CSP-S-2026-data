#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
vector<int>now;
int main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		now.clear();
		for(int j=i;j<=n;j++){
			for(auto k=now.begin();k<now.end();k++){
				if(*k==a[j]){
					now.erase(k,now.end());
					break;
				}
			}
			now.push_back(a[j]);
		}
		for(int G:now)ans[G]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
