#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],C[M],xb[M];//首次出现xb 
int n_n,ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int x=1;x<=n;x++){
		vector<int>tab;
		memset(C,0,sizeof(C));
		for(int i=x-1;i<=n;i++){
			if(C[a[i]]<=0){
				tab.push_back(a[i]);
				C[a[i]]++;
				xb[a[i]]=tab.size();
			}else{
				int l=tab.size();
				for(int j=xb[a[i]]-1;j<l;j++)C[tab[j]]--;
				for(int j=xb[a[i]]-1;j<l;j++)tab.pop_back();
				tab.push_back(a[i]);
				C[a[i]]++;
			}
			if(i==n){
				for(int j=1;j<=m;j++){
					for(int y=0;y<tab.size();y++){
						if(tab[y]==j)ans[j]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
