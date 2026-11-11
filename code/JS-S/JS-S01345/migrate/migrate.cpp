#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans,cnt,tmp,sum;
int a[2000005];
void dfs(int p,int r,int res){
	if(res>ans)return ;
		if(p==r){
			cnt++;
			return ;
		}
	for(int i=r;i>=p+1;i--){
		if(abs(a[i]-a[p])<=d){
			dfs(i,r,res+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				tmp=l;
				ans=1;
				cnt=0;
				for(int i=l;i<=r;i++){
					if(abs(a[i]-a[tmp])>d){
						ans++;
						i--;
						tmp=i;
					}
				}
				dfs(l,r,0);
				if(cnt==2){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
		
	}
	return 0;
}
