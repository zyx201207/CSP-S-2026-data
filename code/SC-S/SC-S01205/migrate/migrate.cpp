#include<bits/stdc++.h>
using namespace std;
const int N=3e2+10;
long long c,t,n,d,r,x[N],cnt[N][N],b[N][N],ans;
int main(){
	//目标：O(N^3)的24分 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(cnt,0,sizeof(cnt));
		memset(b,0x3f,sizeof(b));
		for(int i=1;i<=n;i++){
			cin>>x[i],cnt[i][i]=1,b[i][i]=0;
		}
		
		ans=0;
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				r=l+len-1;
				for(int k=l+1;x[k]-x[l]<=d && k<=r;k++){
					if(1+b[k][r]<b[l][r]){
						b[l][r]=1+b[k][r];
						cnt[l][r]=cnt[k][r];
					}
					else if(1+b[k][r]==b[l][r]){
						cnt[l][r]+=cnt[k][r];
					}
				}
				if(cnt[l][r]==2)ans++;
				//cout<<l<<' '<<r<<' '<<cnt[l][r]<<'\n'; 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 