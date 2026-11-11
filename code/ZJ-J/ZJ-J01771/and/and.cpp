#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
vector<int>vis[50];
vector<int>ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(int j=1;j<40;j++)
			if(x&(long long)(1ll<<j-1))
				vis[j].push_back(i);
	}
	for(int i=40;i>=1;i--){
		if(vis[i].size()<m)continue;
		if(ans.empty())ans=vis[i],sum=1ll<<i-1;
		else {
			vector<int>tmp;
			int Vis=0,Ans=0;
			while(Vis<vis[i].size()&&Ans<ans.size()){
				if(vis[i][Vis]==ans[Ans])tmp.push_back(ans[Ans]),Ans++,Vis++;
				else if(vis[i][Vis]<ans[Ans])Vis++;
				else Ans++;
			}
			if(tmp.size()>=m){
				ans=tmp;
				sum+=1ll<<i-1;
			}
		}
	}
	cout<<sum;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
