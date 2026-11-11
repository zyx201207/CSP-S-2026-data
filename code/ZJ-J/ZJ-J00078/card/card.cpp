#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int maxm=3e5+10;
int n,m,a[maxn],ans[maxm];
//int pre[maxn];
//void init(){
//	map <int,int> mp;
//	for(int i=1;i<=n;i++){
//		if(mp.count(a[i])) pre[i]=mp[a[i]];
//		mp[a[i]]=i;
//	}
//}
//void query(int s){
//	vector<vector<int>> v(n+1);
//	for(int i=s;i<=n;i++){
//		if(pre[i]>=s) v[i]=v[pre[i]];
//		else{
//			v[i]=v[i-1];
//			v[i].push_back(a[i]);
//		}
//	}
//	vector<int> v;
//	for(int i=s;i<=n;i++){
//		auto it=find(v.begin(),v.end(),a[i]);
//		if(it!=v.end()) v.resize(it-v.begin());
//		v.push_back(a[i]);
//	}
//	for(int i:v) ans[i]++;
//}
void query(int s){
	stack<int> st;
	unordered_map<int,int> mp;
	for(int i=s;i<=n;i++){
		if(mp.count(a[i])&&mp[a[i]]){
			while(!st.empty()){
				int now=st.top();
				if(now==a[i]) break;
				st.pop();
				mp[now]--;
			}
		}
		else{
			st.push(a[i]);
			mp[a[i]]++;
		}
	}
	while(!st.empty()){
		ans[st.top()]++;
		st.pop();
	}
}
int main(){
	freopen("card.in","rb",stdin);
	freopen("card.out","wb",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		query(i);
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
}
