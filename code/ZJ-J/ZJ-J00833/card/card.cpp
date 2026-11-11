#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],p[300005],mi[300005];
vector<int> v[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]++;
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int x=1;
		for(int j=1;j<=m;j++){
			if(p[a[j]]-mi[a[j]]){
				if(p[a[j]]-mi[a[j]]>1){
				int y=p[a[j]]-mi[a[j]],t=v[a[j]][((y%2)?p[a[j]]-1:p[a[j]]-2)];
				x=max(t,x);
				}
				mi[a[j]]++;
			}
		}
		for(int k=x;k<=n;k++) ans[a[k]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}