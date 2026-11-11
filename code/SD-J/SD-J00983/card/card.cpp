#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,a[N],l[N],r[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(l[a[i]]==0)l[a[i]]=i;
	}
	for(int i=n;i>=1;--i)if(r[a[i]]==0)r[a[i]]=i;
	for(int i=n;i>=1;--i){
		if(ans[a[i]]==0)ans[a[i]]=i;
		for(int j=1;j<=m;++j){
			if(i==j)continue;
			if(l[j]<i&&i<r[j])--ans[a[i]];
		}
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}
