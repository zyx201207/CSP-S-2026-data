#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans[50],vis[200010],a[200010][50],n,m,maxx,sum;
void zhuan(int num,int k){
	int cnt=0;
	while(num!=0){
		cnt++;
		if(num%2==1){
			a[k][cnt]=1;
		}else{
			a[k][cnt]=0;
		}
		num/=2;
		
	}
	maxx=max(maxx,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		zhuan(t,i);
	}
	for(int i=maxx;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1&&vis[j]==0) cnt++;
		}
		if(cnt<m) ans[i]=0;
		else{
			ans[i]=1;
			for(int j=1;j<=n;j++) {
				if(a[j][i]==0&&vis[j]==0){
					vis[j]=1;
				}
			}
		}
	}
	int p=1;
	for(int i=1;i<=maxx;i++){
		sum+=ans[i]*p;
		p*=2;
	}
	cout<<sum;
	return 0;
} 
