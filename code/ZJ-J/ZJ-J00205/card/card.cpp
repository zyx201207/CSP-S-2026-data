#include<bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int M=5e5+100;
int n,m;
int a[M],b[M],lst[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		memset(lst,0,sizeof(lst));
		for(int j=1;j<=n;j++) b[j]=a[j];
		for(int j=i;j<=n;j++) {
			if(lst[b[j]])
				for(int z=lst[b[j]];z<j;z++)
					lst[b[z]]=0,b[z]=0;
			lst[b[j]]=j;
		}
		for(int j=i;j<=n;j++) ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;     
}     