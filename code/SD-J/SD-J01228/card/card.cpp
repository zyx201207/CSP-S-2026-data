#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int now[N],idx=0;
int ans[N];
int id[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(now,0,sizeof(now));
		memset(id,-1,sizeof(id));
		idx=1;
		for(int j=i;j<=n;j++){
			int r=id[a[j]];
			int iidx=idx;
			if(id[a[j]]!=-1){
				iidx=id[a[j]];
				for(int k=id[a[j]];k<idx;k++){
					id[now[k]]=-1;
				}
			}
			now[iidx]=a[j];
			id[a[j]]=iidx;
			idx=iidx;
			idx++;
		}
		for(int j=1;j<idx;j++){
			ans[now[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m){
			cout<<" ";
		}
	}
	return 0;
}
