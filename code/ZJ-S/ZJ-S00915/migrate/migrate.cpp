#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m;
const int maxn=2000005;
int a[maxn],ans,flag,ang,ank;
bool mp[maxn];
int minn(int l1,int l2){
	if(l1<=l2){return l1;}
	else{return l2;}
}
int maxx(int l1,int l2){
	if(l1>=l2){return l1;}
	else{return l2;}
}
void dfs(int x,int y,int t){
	if(x==y){ans=minn(ans,t);return ;}
	for(int i=x;i<=n;i++){
		if(mp[i]!=1&&abs(a[i]-a[x])<=m){
			//cout<<i<<" ";
			mp[i]=1;
			dfs(i,y,t+1);
			mp[i]=0;
		}
	}
}
void dfs2(int x,int y,int t){
	if(x==y&&t==ans){return ;}
	for(int i=x;i<=n;i++){
		if(mp[i]!=1&&abs(a[i]-a[x])<=m){
			//cout<<i<<" ";
			mp[i]=1;
			dfs(i,y,t+1);
			mp[i]=0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){cin>>a[i];}
		flag=1;ank=0;
//		for(int i=2;i<=n;i++){
//			if((a[i]-a[i-1])!=(a[2]-a[1])){
//				flag=0;break;
//			}
//		}
//		if(flag=1){
//			if(2*(a[2]-a[1])>m){cout<<"0\n";}
//			else{ans=0;
//				for(int i=1;i<=n;i++){
//					ans=ans+maxx(0,n-(i+m+1)+1);
//					ans=ans-(a[n]-a[i])/(a[2]-a[1])/(m/(a[2]-a[1]))+1;
//				}cout<<ans<<"\n";
//			}
//		}else{
			//memset(mp,0,sizeof(mp));
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					//cout<<"\n"<<i<<" "<<j<<":\n";
					memset(mp,0,sizeof(mp));
					mp[i]=1;
					ans=INT_MAX;
					dfs(i,j,0);
					memset(mp,0,sizeof(mp));
					mp[i]=1;
					//cout<<"\n"<<ans<<"<----------------\n";
					ang=0;
					dfs2(i,j,0);
					if(ang>=2){ank++;}
				}
			}cout<<ank<<"\n";
//		}
	}
	return 0;
}
