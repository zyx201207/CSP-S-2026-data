#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[500001];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int s=1;s<=n;s++){
		vector<int> p(n+1);
		for(int i=s;i<=n;i++){
			bool f=0;int id;
			for(int j=0;j<p.size();j++)
				if(p[j]==a[i]){
					f=1;
					id=j;
				}
			if(f)
				for(;id<=p.size();)
					p.pop_back();
			p.push_back(a[i]);
		}
		for(int i=0;i<p.size();i++)
			ans[p[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
}
