#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
bool vis[200005];
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	int sum=-1,cura,curb;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(sum< (a[i]&a[j])){
				sum=a[i]&a[j];
				cura=i,curb=j;
			}
		}
	}
	vis[cura]=1;
	vis[curb]=1;
	while(m--){
		int maxx=-1,cur;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(maxx< (a[i]&sum)){
				maxx=a[i];
				cur=i;
			}
		}
		vis[cur]=1;
		sum=sum&maxx;
	}
	cout<<sum;
	return 0;
}
