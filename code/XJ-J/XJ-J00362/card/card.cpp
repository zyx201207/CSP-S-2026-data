#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[300005],d,ans[300005];
bool c[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)
		if(c[a[i]]==0)l[a[i]]=i,c[a[i]]=1;
	for(int i=1;i<=n;i++){
		d=i;
		while(d<=n){
			ans[a[d]]++;
			d=l[a[d]]+1;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
