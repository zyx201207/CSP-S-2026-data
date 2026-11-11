#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5011;
int c,q,n,a[N],v,sta[N],pre[N],pstep[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>v;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;

		for(int i=1;i<=n;i++){
			
			int tot=i;
			for(int j=i;j<=n;j++){
				while(tot<j&&a[j]-a[tot]>v){
					tot++;
				}
				pre[j]=tot;
			}
			for(int j=1;j<=n;j++) {
				if(pre[j]==j) pstep[j]=0;
				else pstep[j]=pstep[pre[j]]+1;
			}	
			
			for(int j=1;j<=n;j++) sta[j]=0;
			sta[i]=1;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[j-1]>v) break;
				int cur=max(pre[j],i);
				sta[j]=sta[cur];
				if(cur+1<j&&pstep[cur+1]==pstep[cur]){
					sta[j]+=sta[cur+1];
					if(cur+2<j&&pstep[cur+2]==pstep[cur]) sta[j]+=sta[cur+2];
				}
				if(sta[j]>2) sta[j]=3;
				//if(i==2) cout<<sta[j]<<endl;
				if(sta[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
/*
1 1
5 2
1 2 3 4 5

jiushicai meibanfa
*/
