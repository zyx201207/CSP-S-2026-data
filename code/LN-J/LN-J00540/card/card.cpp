#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<string> a(n);
	map<string,int> ans;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int j=0;j<n;j++){
		vector<string> x;
		for(int i=j;i<n;i++){
			int k=-1;
			for(int u=0;u<x.size();u++){
				if(x[u]==a[i]){
					k=u;
					break;
				}
			}
			if(k+1)x.resize(k);
			x.push_back(a[i]);
		}
		for(int i=0;i<x.size();i++)ans[x[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[to_string(i)]<<' ';
	cout<<'\n';
	return 0;
}
