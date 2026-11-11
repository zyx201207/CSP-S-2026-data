#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt,ans;
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=30;~i;i--){
		cnt=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(a[j]&(1<<i))) cnt++;
		if(cnt>=m){
			for(int j=1;j<=n;j++)
				if(!(a[j]&(1<<i))) vis[j]=true;
			ans+=(1<<i);
		}
	}
	printf("%d\n",ans);
	return 0;
}