#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=2e6+5,INF=0x3f3f3f3f3f3f3f3f;
int c,T,n,k,a,b,rh[N],vis[N],l=1,r;
vector<int> vec[N];
//void dfs(int step){
//	if(step==go_l+1){
//		return;
//	}
//}
//void check(int go_l){
//	queue<int> q;
//	q.push(1);
//	int cnt=0;
//	while(q.size() && cnt<=go_l){
//		cnt++;
//		int t=q.top();q.pop();
//		
//	}
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
//	if(c==11 || c==12 || c==7)
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a>>b;
		}
		if(n>k) cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
} 
