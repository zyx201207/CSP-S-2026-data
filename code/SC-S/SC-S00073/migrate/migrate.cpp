#include<bits/stdc++.h>
using namespace std;
const int maxn=6000;
int a[maxn],pre[maxn]={0},m[maxn]={0};
int dis[maxn][maxn]; 
int n,d;
int cnt,k;
int  dfs(int l,int r,int p,int k,int cnt){
	for(int i=r;i>=l;i--){
		if(pre[i]-pre[k]<d&&i!=p){
			cnt++;
			k=i;
			i=k-1;
		}
	}
	if(k==r){
		return cnt;
	}
	return 0;
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c!=11&&c!=12&&c!=13&&c!=14&&c!=15&&c!=16&&c!=17&&c!=18){
		while(t--){
			cin>>n>>d;
			//cout<<n<<" "<<d<<endl;
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				pre[i]=pre[i-1]+a[i];
			}
//			for(int l=1;l<=n;l++){
//				for(int r=1;r<=n;r++){
//					dis[l][r]=pre[r]-pre[l];
//				}
//			}
			for(int l=1;l<=n;l++){
				for(int r=1;r<=n;r++){
					for(int p=0;p<=n;p++){
						if(!dfs(l,r,p,l,cnt)){
							m[cnt]++;
							//cout<<m[cnt]<<" ";
						}
					}
					for(int i=1;i<=n;i++){
						if(m[i]==2){
							ans++;
						}
					}
				}
			}
			cout<<ans<<'\n';	
			for(int i=1;i<=n;i++){
				a[i]=0;
				pre[i]=0;
				m[i]=0;
			}
		}
	}
	return 0;
}