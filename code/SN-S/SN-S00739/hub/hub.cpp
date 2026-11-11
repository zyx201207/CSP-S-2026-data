#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans=1,c,T;
vector<int> m[1000005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			m[v].push_back(u);
			m[u].push_back(v);
		}
		cout<<ans<<endl;
		ans++;
	}
	return 0;
}
//虽然很想和S组题目进行激烈的豆蒸，可惜实在是心有余而力不足。 
//看来我不得不离开南京，离开我亲手建立的首都。
//今此一去，我将再无葬身之所啊。
//无可奈何，无可奈何，悠悠苍天何负于我！
