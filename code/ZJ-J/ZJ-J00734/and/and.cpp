#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int cnt[35];
bool f[200005][35];
int now;
vector<int> g,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	now=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g.push_back(i);
	}
	for(int bit=31;bit>=0;bit--){
		for(int i=1;i<=n;i++){
			if((a[i]>>bit)&1){
				f[i][bit]=1;
//				cnt[bit]++;
			}
		}
//		if(cnt[bit]>m)break;
	}
	for(int bit=31;bit>=0;bit--){
//		if(now<=m)break;
//		int twt=g.size();
		for(int i=0;i<g.size();i++){
			if(f[g[i]][bit]){
				t.push_back(g[i]);
			}
		}
//		for(int i=0;i<t.size();i++){
//			cout<<t[i]<<" ";
//		}
//		cout<<"\n";
		if(t.size()>=m){
			g.clear();
			for(int i=0;i<t.size();i++){
				g.push_back(t[i]);
			}
	 		
		}t.clear();
		now=g.size();
//		for(int i=0;i<g.size();i++){
//			cout<<g[i]<<" ";
//		}
//		cout<<"\n\n\n";
	}
	int ans=a[g[0]];
//	cout<<g.size()<<" ";
//	cout<<g[0]<<" ";
	for(int i=1;i<m;i++){
		ans&=a[g[i]];
//		cout<<g[i]<<" ";
	}
	cout<<ans;
	return 0;
}