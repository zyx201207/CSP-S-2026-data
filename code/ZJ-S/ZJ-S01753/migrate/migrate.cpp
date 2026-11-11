#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,n,f[N],g[N];
ll d,x[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			f[i]=0;
			g[i]=1; //
			int l=i,r=i,sum=1,cnt=0;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d) break;
				while(x[j]-x[l]>d){
					if(g[l]==-1) cnt--;
					else sum-=g[l];
					l++;
				}
				f[j]=f[l]+1;
				if(r<l){
					r=l;
					if(g[l]==-1) sum=0,cnt=1;
					else sum=g[l],cnt=0;
				}
				while(r+1<j&&f[r+1]==f[r]){
					r++;
					if(g[r]==-1) cnt++;
					else sum+=g[r];
				}
				if(cnt>0||(cnt==0&&sum>2)){
					g[j]=-1;
				}else{
					g[j]=sum;
					if(sum==2){
						ans++;
						cout<<i<<' '<<j<<'\n';
					}
				}
//			for(int j=i+1;j<=n;j++) cout<<g[j]<<" \n"[j==n];		
			}
			for(int j=i;j<=n;j++) f[j]=g[j]=0;	
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
