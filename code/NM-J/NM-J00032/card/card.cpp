#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],hv[500010];
vector<int>v;
bool hv2[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		v.clear();
		memset(hv2,0,sizeof(hv2));
		for(int j=i;j<=n;j++){
			if(hv2[a[j]]){
				while(v.back()!=a[j]&&!v.empty()){
					hv2[v.back()]=0;
					v.pop_back();
				}
			}else {
				hv2[a[j]]=1;
				v.push_back(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			if(hv2[i]) hv[i]++;
		}
	}for(int i=1;i<=m;i++) cout<<hv[i]<<" ";
	return 0;
}
