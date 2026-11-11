#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],p[N],nx[N],ans[N],fa[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(p[a[i]]!=0){
			nx[p[a[i]]]=i;
			fa[a[i]]=i;
		}
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(nx[j]!=0) j=fa[a[j]];
			else{
				ans[a[j]]++;
				j++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
