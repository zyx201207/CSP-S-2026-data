#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int c,t,n,d,sum[maxn],q[maxn],a[maxn],sum2[maxn],q2[maxn];
//vector<int>q[maxn];
bool p(int x,int y){
	return abs(a[x]-a[y])<=d;
}
void solve(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0,cnt=0;
	if(c<=10){
		for(int i=1;i+3<=n;i++){
			if((!p(i,i+3))&&p(i,i+1)&&p(i,i+2)&&p(i+1,i+3)&&p(i+2,i+3)){
				q[i]=1;	
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int fl=0;
				for(int o=i;o<=j;o++){
					if(q[o]!=0&&o+3<=j){
						fl++;
					}
				}
				if(fl==1)ans++;
			}
		}
		cout<<ans<<'\n';
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(a[j]-a[i]<=d){
//					q[i].push_back(j);
//				}
//			}
//		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	} 
	return 0;
}

