#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],f[N],tmp[N],flg,ans;
vector<int> r[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int k=0;k<30;k++)
			if(a[i]&(1<<k))
				r[k].push_back(i);
	}
	for(int i=29;i>=0;i--){
		if(r[i].size()<m) continue;
		if(flg==0){
			for(int x:r[i]) f[x]=1;
			flg=1;
		}
		else{
			memset(tmp,0,sizeof(tmp));
			int cnt=0;
			for(int x:r[i]){
				if(f[x]) cnt++;
				tmp[x]=1;
			}
			if(cnt<m) continue;
			for(int i=1;i<=n;i++) if(f[i]&&!tmp[i]) f[i]=0;
		}
		ans+=(1<<i);
	}
	printf("%d\n",ans);
	return 0;
}
