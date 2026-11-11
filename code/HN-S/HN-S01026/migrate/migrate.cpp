#include<bits/stdc++.h>
using namespace std;
int mp[50005],cnt[50005],vis[50004],k[50004];
int c,t;
int n,d;
void dfs(int s,int e,int num){
	if(s==e){
		if(k[s]==num)cnt[s]++;
		else if(num<k[s]){
			k[s]=num;cnt[s]=1;
		}
		return;
	}
	int h=s+1;
	while(mp[s]+d>=mp[h]){
		if(!vis[h]){
			vis[h]=1;
			dfs(h,e,num+(mp[h]-mp[s]));
			h++;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>mp[i];
		long long num=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				k[j]=INT_MAX;
				dfs(i,j,0);
				if(cnt[j]==2)num++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
} 
