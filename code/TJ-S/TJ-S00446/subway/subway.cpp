#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q,w[500005],ans = 0,t[500005],cnt[500005];
vector<int> s[500005],ti[500005];
void pfs(int x){
	if(t[x]) return;
	t[x] = 1;
	for(int i = 0;i < s[x].size();i++){
		if(t[s[x][i]]) continue;
		ans += (cnt[x] + ti[x][i]);
		//cout<<x<<" "<<i<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	int k,a,t,la,lt;
	for(int i = 1;i <= n;i++){
		cin>>k;
		for(int j = 1;j <= k;j++){
			cin>>a>>t;
			if(j == 1){
				la = a;
				lt = t;
				continue;
			}
			s[la].push_back(a);
			s[a].push_back(la);
			ti[la].push_back(t);
			ti[a].push_back(t);
			
		}
	}
	int x,y;
	for(int i = 1;i <= q;i++){
		cin>>x>>y;
		ans = w[x] + w[y];
		
		pfs(x);
		cout<<ans<<endl;
	}
	return 0;
}

