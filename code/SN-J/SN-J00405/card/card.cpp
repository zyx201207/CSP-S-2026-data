#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int first[500005];
int last=0;
int ans[500005];
int xu[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) first[j]=-1;
		for(int j=1;j<=n;j++) xu[j]=0;last=0;
		for(int j=i;j<=n;j++){
			if(first[a[j]]==-1){
				last++;first[a[j]]=last;xu[last]=a[j];
			}
			else{
				for(int s=first[a[j]]+1;s<=last;s++){
					if(first[xu[s]]==s) first[xu[s]]=-1;xu[s]=0;
				}
				last=first[a[j]];
			}
		}
		for(int j=1;j<=m;j++) if(first[j]!=-1) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
