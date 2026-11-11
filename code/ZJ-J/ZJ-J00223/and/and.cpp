#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200010];
int t[40][200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=0;
	vector<int> g,h;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int j=1;
		while(a[i]>0){
			t[j++][i]=a[i]%2;
			a[i]/=2;
		}
		g.push_back(i);
		mx=max(mx,j-1);
	}
	int ans=0;
	for(int i=mx;i>=1;i--){
		int sum=0;
		for(int j=0;j<g.size();j++){
			sum+=t[i][g[j]];
		}
		if(sum>=m){
			for(int j=0;j<g.size();j++){
				if(t[i][g[j]]==1){
					h.push_back(g[j]);
				}
			}
			g.clear();
			for(int j=0;j<h.size();j++){
				g.push_back(h[j]);
			}
			h.clear();
			ans+=pow(2,i-1);
		}
	}
	cout<<ans;
	return 0;
}