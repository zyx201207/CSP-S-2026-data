#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt,pre[N],ans[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	for(int i=1; i<=n; ++i){
		memset(pre, 0, sizeof pre);
		vector<int> vt(n+5, 0);
		cnt=0;
		for(int j=i; j<=n; ++j){
			if(pre[a[j]]){
				for(int k=pre[a[j]]+1; k<=cnt; ++k){
					pre[vt[k]]=0;
				}
				cnt=pre[a[j]];
			} else{
				vt[++cnt]=a[j];
				pre[a[j]]=cnt;
			}
		}
		for(int i=1; i<=cnt;++i){
			ans[vt[i]]++; 
		} 
	}
	for(int i=1; i<=m; ++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

