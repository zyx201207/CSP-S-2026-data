#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,l[200005],a[200005],sw[200005][32]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		l[i]=1;
		cin>>a[i];
		int x=a[i],j=0;
		while(x!=0){
			sw[i][j]=x&1;
			x/=2;
			j++;
		}
	}for(int j=29;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++)if(l[i])cnt+=sw[i][j];
		if(cnt<m)continue;
		for(int i=1;i<=n;i++)if(l[i])l[i]=sw[i][j];
		ans+=(1<<j);
	}cout<<ans;
	return 0;
}
