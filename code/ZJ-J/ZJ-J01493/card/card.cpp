#include<bits/stdc++.h>
using namespace std;
int a[500010];
vector<int> v[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> now;
		now.push_back(0);
		int s=now.size();
		for(int j=i;j<=n;j++){
			s=now.size();
			for(int k=1;k<s;k++){
				if(a[j]==now[k]){
					for(int w=k;w<s;w++){
						now[w]=0;
					}
					break;
				}
			}
			now.push_back(a[j]);
		}
		s=now.size();
		for(int j=0;j<s;j++){
			if(now[j]==0)continue;
			else v[i].push_back(now[j]);
		}
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int s=v[j].size();
			for(int w=0;w<s;w++){
				if(v[j][w]==i){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
