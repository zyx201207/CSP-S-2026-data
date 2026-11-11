#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],fi=-1,vis[200005]={0},sum=0;
vector<int> e[35];
set<int> se[35];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int tp=0;
		while(a[i]!=0){
			if(a[i]%2==1) e[tp].push_back(i);
			tp++;
			a[i]/=2;
	    }
	}for(int i=30;i>=0;--i){
		if((int)e[i].size()>=m){
			fi=i;
			for(int j=0;j<(int)e[i].size();++j) vis[e[i][j]]=1;
			sum+=(1<<i);
			break;
		}
	}if(fi==-1){
		cout<<0;
		return 0;
	}for(int i=fi-1;i>=0;--i){
		int cnt=0;
		for(int j=0;j<(int)e[i].size();++j){
			if(vis[e[i][j]]) cnt++;
		}if(cnt>=m){
			sum+=(1<<i);
			for(int j=0;j<(int)e[i].size();++j){
				if(vis[e[i][j]]) vis[e[i][j]]=2;
			}for(int j=1;j<=n;++j){
				if(vis[j]==1) vis[j]=0;
				if(vis[j]==2) vis[j]=1;
			}
		}
	}cout<<sum;
	return 0;
}
