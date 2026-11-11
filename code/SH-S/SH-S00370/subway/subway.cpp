#include <bits/stdc++.h>
#define maxn 505
#define maxm 500005
#define maxk 500005
using namespace std;
int c,n,m,d,q;
vector<int> sta[maxm];
vector<int> stt[maxm];
bool check[maxm];
int dfs(int st,int ed){
	check[st]=true;
	int ans=-1,cnt;
	if(st==ed){
		return stt[st][0];
	}
	for(int i=0;i<int(sta[st].size());i++){
		if(check[sta[st][i]]==false){
			ans=max(ans,dfs(sta[st][i],ed))+stt[st][i];
		}
	}
	check[st]=false;
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1;i<=n;i++){
		cin>>w[i]; 
	}
	int k,a1,t1,a2,t2;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a1>>t1>>a2>>t2;
			sta[a1].push_back(a2);
			sta[a2].push_back(a1);
			stt[a1].push_back(t1);
			stt[a2].push_back(t2);
		}
	}
	int st,ed;
	int ans;
	for(int i=0;i<q;i++){
		cin>>st>>ed;
		memset(check,false,sizeof(check));
		ans=w[st]+w[ed];
		ans+=dfs(st,ed);
		cout<<ans<<"\n";
	}
	return 0;
}

