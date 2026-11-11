#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int minn[300010],maxx[300010];
bool vis1[300010],vis2[300010];
int cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)minn[j]=1e9,maxx[j]=-1;
		for(int j=i;j<=n;j++){
			if(minn[a[j]]==1e9)minn[a[j]]=j;
			maxx[a[j]]=max(maxx[a[j]],j);
		}
		for(int j=1;j<=m;j++){
			bool f=1;
			
			if(minn[j]==1e9||maxx[j]==-1)continue;
			
			if(minn[j]==i||maxx[j]==n){
				cnt[j]++;
				continue;
			}
			
			for(int k=1;k<=m;k++)vis1[k]=vis2[k]=0;
			
			for(int k=i;k<minn[j];k++)vis1[a[k]]=1;
			
			for(int k=maxx[j]+1;k<=n;k++)vis2[a[k]]=1;
			
			for(int k=1;k<=m;k++)if(vis1[k]&&vis2[k])f=0;
			
			if(f)cnt[j]++;
		}
		
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
}
//gugugaga gugugaga gugugaga!!!
