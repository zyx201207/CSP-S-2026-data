#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N];
int g[N];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=1;
		set<int> s;
		for(int j=i;j<=n;j++){
			bool flag=false;
			int id=1;
			for(int l=1;l<=t;l++){
				if(g[l]==a[j]){
					flag=true;
					id=l;
					break;
				}
			}
			if(flag){
				g[id]=a[j];
				for(int l=id+1;l<=t;l++) g[l]=0;
				t=id+1;
			}else g[t++]=a[j];
		}
		for(int j=1;j<t;j++){
			s.insert(g[j]);
			g[j]=0;
		}
		for(int k:s) ans[k]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 

