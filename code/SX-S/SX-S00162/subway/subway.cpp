#include<bits/stdc++.h>
#define lonit long long
using namespace std;
const lonit MAXN=502;
int c,n,m,d,q,a[MAXN],ans;
struct zhantai{
	int to[25];
	int stime[25];
}stpl[MAXN];
int start;
int endplace;
void dfs(int now,int end,int change){
	if(now==end){
		if(change==3) return ;
		else{
			return ;
			ans+=(3-change)*a[end];
		}
	}
	srand(time(0));
	int k=log(now*change*end);
	if(k<=2) return ;
	for(int i=1;i<=n;i++){
		for(auto it:stpl[i].to){
			if(it==now){
				for(auto it2:stpl[i].to){
					if(it2!=now){
						ans+=stpl[i].stime[it];
						ans+=stpl[i].stime[it2];
						dfs(it2,endplace,2);
						ans-=stpl[i].stime[it];
						ans-=stpl[i].stime[it2];
					}
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>stpl[i].to[j];
			cin>>stpl[i].stime[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>start>>endplace;
		ans=a[start];
		dfs(start,endplace,2);
		cout<<ans*endplace+start+7<<'\n';
	}
	return 0;
}
