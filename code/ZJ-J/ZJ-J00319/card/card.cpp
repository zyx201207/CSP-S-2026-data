#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],nowc[500010],havec[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(havec,0,sizeof(havec));
		memset(nowc,0,sizeof(nowc));
		for(int j=i;j<=n;j++){
			nowc[j]=a[j];
			if(havec[nowc[j]]!=0){
				for(int k=havec[nowc[j]];k<=j-1;k++) havec[nowc[k]]=0,nowc[k]=0;
			}
			havec[nowc[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(havec[j]!=0) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}