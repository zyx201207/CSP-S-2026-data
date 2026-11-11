#include<bits/stdc++.h>
using namespace std;
int n,a[500010],m,ans[300010];
int t[300010];
int st[500010];
int la[300010];
int to;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		to=0;
		for(int j=i;j<=n;j++){
			to++;
			st[to]=a[j];
			if(t[a[j]]==i){
				for(int u=to;u>la[a[j]];u--)t[st[u]]=-1;
				to=la[a[j]];
			}
			t[a[j]]=i;la[a[j]]=to;
		}
		for(int j=1;j<=m;j++){
			if(t[j]==i)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
