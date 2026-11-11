#include<bits/stdc++.h>
using namespace std;
int n,m,d[200005],a[200005],ans[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> e;
		e.clear();
		e.push_back(0);
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++){
			if(d[a[j]]){
				int lenth=e.size();
				for(int k=d[a[j]];k<lenth;k++) {
					d[e[k]]=0;
					e[k]=0;
				}
			}
			e.push_back(a[j]);
			d[a[j]]=j;
		}
		int long_1=e.size();
		for(int j=0;j<long_1;j++){
			ans[e[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
