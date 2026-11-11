#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		vector<int>v;
		vector<int>k;
	for(int i=1;i<=n;i++){
		k=v;
		for(int j=i;j<=n;j++){
			int len=v.size();int x=0;
			for(int k=0;k<len;k++){
				if(v[k]==a[j]){
					x=k;break;
				}
			}
				if(x)v.erase(v.begin()+x,v.end());
				v.push_back(a[j]);
		}
		for(auto amd:v)ans[amd]++;
	}
		for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]!=a[j-1])ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
