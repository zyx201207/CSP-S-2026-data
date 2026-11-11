#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010,M=2e6+3;
#define endl "\n"
int n,d;
int a[M];
int ans[N][N];
void dfs(int now,int cnt){
	int i=now+1;
	while(a[i]-a[now]<=d and i<=n){
		ans[i][cnt+1]++;
		dfs(i,cnt+1);
		i++;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int tmp=0;
		cin>>n>>d;
		int tmp1=-1;
		bool ta=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2){
				int tmp2=a[i]-a[i-1];
				if(tmp1==-1)tmp1=tmp2;
				if(tmp2!=tmp1)ta=false;
			}
		}
		if(false){
			int now=d/tmp1;
			if(now==0)cout<<0<<endl;
			else{
				int l=a[n]-a[1];
				cout<<(l-now*tmp1*2+d>0?(l-now*tmp1*2+d)/d+1:0)<<endl;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				memset(ans,0,sizeof(ans));
				dfs(i,0);
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=n;k++){
						if(ans[j][k]!=0){
							if(ans[j][k]==2)tmp++;
							break;
						} 
					} 
				}
			}
			cout<<tmp<<endl;
		}
	}
	return 0;
}
