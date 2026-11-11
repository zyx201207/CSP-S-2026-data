#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[201010];
vector<int> v;
vector<int> st[300010];
int cntz[201010];
int cnt[201010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt)); 
		for(int j=i;j<=n;j++){
			if(cnt[a[i]]){
				v.clear();
			}v.push_back(a[i]);
			cnt[a[i]]++;
		}for(auto c:v){
			st[c].push_back(1);
		}
	}for(int i=1;i<=m;i++){
		cout<<st[i].size()<<" ";
	}
	return 0;
}
