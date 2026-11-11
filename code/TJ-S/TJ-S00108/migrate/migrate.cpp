#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=5005;
const ll inf=2e18;
int c,t,n;
ll d,x[mxn],dis[mxn],mn[mxn],ans;
void sv(int nw){
	for(int i=nw;i<=n;i++){
		dis[i]=0;
		mn[i]=inf;
	} 
	dis[nw]=1;
	mn[nw]=0;
	for(int i=nw;i<=n;i++){
		if (dis[i]>2) continue;
		for(int j=i;j<=n;j++){
			if (x[j]-x[i]>d) break;
			if (mn[i]+1==mn[j]){
				dis[j]+=dis[i];
			}else if (mn[i]+1<mn[j]){
				dis[j]+=dis[i];
				mn[j]=mn[i]+1;
			} 
		}
	}
	for(int i=nw;i<=n;i++){
		if (dis[i]==2) {
			ans++;
		}	
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			sv(i);
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
