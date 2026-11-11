#include<bits/stdc++.h>
using namespace std;
long long t,n,d;
void solve(){
	cin>>n>>d;
	int ls[n+9];
	long long ans=0;
	for(int i = 1;i <= n;i ++){
		cin>>ls[i];
	} 
	for(int i = 1;i <= n;i ++){
		int cnt[n+9]={},dis[n+9]={};
		cnt[i]=1;
		for(int nw=i;nw<=n;nw++){
			if(cnt[nw]==2)ans++;
			for(int j = nw+1;j<=n&&ls[j]-ls[nw]<=d;j ++){
				if(dis[j]==0)dis[j]=dis[nw]+1;
				if(dis[nw]<dis[j])cnt[j]+=cnt[nw];
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	for(int i = 0;i < t;i ++)
		solve(); 
	return 0;
} 
