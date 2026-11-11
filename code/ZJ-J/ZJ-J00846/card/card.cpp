#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],r[500005],ans[500005];
bool ok[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		r[i]=i+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r[p[a[i]]]=i;
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j=r[j]){
			ok[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
			if(ok[j]){
				ok[j]=0;
				ans[j]++;
			}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}