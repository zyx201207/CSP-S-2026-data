#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,g1,dq,a[500005],ans[500005]={99999999},map2[500][500],qs,zd;
bool map1[500][500];
void dfs(int ps,int t2,int dq){
	if(dq==zd){
		ans[g1]=min(t2,ans[g1]);
		cout<<t2<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(map2[i][dq]>0&&!map1[i][dq]){
			map1[i][dq]=1;
			dfs(i,t2+map2[i][dq],dq);
			map1[i][dq]=0;
		}
	}
	for(int i=0;i<m;i++){
		if(map2[ps][i]>0&&!map1[ps][i]){
			dfs(ps,t2+map2[i][dq],i);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>a[i];
	int a1,b,l,p;
	for(int i=0;i<n;i++){
		cin>>a1>>l>>b>>p;
		map2[i][a1]=l;
		map2[i][b]=p;
	}
	for(int i=0;i<q;i++){
		cin>>qs>>zd;
		for(int i=0;i<n;i++){
			if(map2[i][qs]>0){
				map1[i][qs]=1;
				dfs(i,a[qs],dq);
			}
		} 
		g1++;
	}
	for(int i=0;i<g1;i++)cout<<ans[i]<<endl;
}
