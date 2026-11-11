#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,s[2001000],ans[5010][5010],num[5010][5010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ans[i][j]=1e18;
					num[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				cin>>s[i];
			}
			if(n==1){
				cout<<0<<"\n";
				continue;
			}
			for(int i=1;i<=n;i++){
				int r=upper_bound(s+1,s+n+1,s[i]+d)-s-1;
				for(int j=i;j<=r;j++){
					ans[i][j]=1;
					num[i][j]=1;
				}
			}
			for(int len=2;len<=n;len++){
				for(int l=1;l+len-1<=n;l++){
					int r=l+len-1;
					if(ans[l][r]==1){
						continue;
					}
					for(int k=r-1;k>=l;k--){
						if(s[r]-s[k]<=d){
							if(ans[l][r]>ans[l][k]+1){
								ans[l][r]=ans[l][k]+1;
								num[l][r]=num[l][k];
								if(num[l][r]>3){
									num[l][r]=3;
								}
							}else if(ans[l][r]==ans[l][k]+1){
								num[l][r]+=num[l][k];
								if(num[l][r]>3){
									num[l][r]=3;
								}
							}
						}else{
							break; 
						}
					}
				}
			}
			int res=0;
			for(int l=1;l<=n;l++){
				for(int r=l+1;r<=n;r++){
					if(num[l][r]==2){
						res++;
					}
				}
			}
			cout<<res<<"\n";
		}
	}else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>s[i];
			}
			if(n==1){
				cout<<"0"<<"\n";
				continue;
			}
			d/=(s[2]-s[1]);
			if(d==0||d==1){
				cout<<"0"<<"\n";
				continue;
			}
			cout<<max(0ll,n-2*d+1)<<"\n";
		}
	}else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>s[i];
			}
			if(n==1){
				cout<<"0"<<"\n";
				continue;
			}
			int cnt=0,lpa;
			for(int i=1;i<=n;i++){
				if(s[i]-s[1]<=d&&s[n]-s[i]<=d){
					lpa=i-1;
					while(s[i]-s[1]<=d&&s[n]-s[i]<=d){
						i++;
						cnt++;
					}
					break;
				}
			}
			if(cnt==2){
				cout<<lpa*(n-lpa-2)<<"\n";
			}else{
				cout<<"0\n";
			}
		}
	}
	return 0;
}
