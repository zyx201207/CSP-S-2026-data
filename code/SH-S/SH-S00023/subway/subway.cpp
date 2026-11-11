#include<bits/stdc++.h>
using namespace std;
struct station{
	int t;
	vector <int> s;
};
struct subway{
	vector <int> t,s;
};
vector<station> sta;
vector<subway> sub;
int dfs(int su,int st,int ends,int fromst){
	if(st == ends){
		int ans = sta[st].t;
		for(int i = 0;i < (int)sub[su].s.size();i++){
			if(sub[su].s[i] == st){
				ans += sub[su].t[i];
				break;
			} 
		}
		return ans;
	}
	int ans = 2147483647;
	int i;
	for(i = 0;i < (int)sub[su].s.size();i++){
		if(sub[su].s[i] == st){
			break;
		} 
	}
	if(sub[su].s[i + 1] != fromst) ans = min(ans,dfs(su,sub[su].s[i - 1],ends,st));
	if(sub[su].s[i - 1] != fromst) ans = min(ans,dfs(su,sub[su].s[i + 1],ends,st));
	for(int j = 0;j < (int)sta[st].s.size();j++){
		int k;
		for(k = 0;k < (int)sub[sta[st].s[j]].s.size();k++){
			if(sub[j].s[k] == st){
				break;
			} 
		}
		ans = min(sub[su].t[i]+sub[sta[st].s[j]].t[k]+min(dfs(sta[st].s[j],sub[sta[st].s[j]].s[k - 1],ends,st),dfs(sta[st].s[j],sub[sta[st].s[j]].s[k + 1],ends,st)),ans);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	sta.resize(m + 1);
	sub.resize(n + 1);
	for(int i = 1;i <= m;i++){
		cin >> sta[i].t;
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 0;j < k;j++){
			int t,s;
			cin >> s >> t;
			sub[i].s.push_back(s),sub[i].t.push_back(t);
			sta[s].s.push_back(i);
		}
	}
	while(q){
		q--;
		int start,end;
		cin >> start >> end;
		int ans = 2147483647;
		for(int i = 0;i < (int)sta[start].s.size();i++){
			int k;
			for(k = 0;k < (int)sub[sta[start].s[i]].s.size();k++){
				if(sub[i].s[k] == start){
					break;
				} 
			}
			ans = min(ans,sta[start].t + sub[sta[start].s[i]].t[k] + dfs(sta[start].s[i],start,end,-1));
		}
		cout << ans << endl;
	}
	return 0;
}
