#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,tmp,maxx,nows,ans;
vector<int>tong[35];
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tmp=a[i];
		int j=0;
		while(tmp){
			if(tmp&1)tong[j].push_back(i);
			tmp>>=1;
			j++;
		}
		maxx=max(maxx,j);
	}
	for(int i=maxx;i>=0;i--){
		if(nows>=m){
			int sum=0;
			for(int j=1;j<=n;j++){
				if(!vis[j])continue;
				if((a[j]>>i)&1)sum++;
			}
			if(sum>=m){
				ans+=(1<<i);
				for(int j=1;j<=n;j++){
					if(!vis[j])continue;
					if(!((a[j]>>i)&1))vis[j]=0;
				}
			}
		}else if(tong[i].size()>=m){
			nows=tong[i].size();
			for(int j=0;j<tong[i].size();j++)vis[tong[i][j]]=1;
			ans+=(1<<i);
		}
	}
	printf("%d",ans);
	return 0;
}


