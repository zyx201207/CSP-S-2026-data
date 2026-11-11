#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,mid,sum=INT_MAX,cnt=0,far[N],near[N];
vector<int> vis[N];
void dfs(int x,int fa,int dep,int mid){
	int lens=vis[x].size();
	for(int i=0;i<lens;i++){
		int y=vis[x][i];
		if(y==fa) continue;
		dfs(y,x,dep+1,mid);
	}
	if(far[x]+near[x]-2*dep>mid){
		near[x]=dep;
		far[x]=0;
		cnt++;
	}
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			vis[u].push_back(v);
			vis[v].push_back(u);
		} 
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(k==2){
			int l=0,r=n;
			while(l<n){
				mid=l+r>>1;
				dfs(1,0,0,mid);
				if(cnt<=2) r=mid;
				else l=mid+1;
			}
			cout<<l;
			return 0;
		}
		else{
			int l=0,r=n;
			while(l<n){
				mid=l+r>>1;
				dfs(1,0,0,mid);
				if(cnt<=k) r=mid;
				else l=mid+1;
			}
			cout<<l;
		}
	}
	return 0;
} 
