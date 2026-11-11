#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans=0,use[25];
int sz_mx=0,vis[200005],bj[40];
string ejz[200005];
void dfs(int now,int cnt){
	if(now==n+1){
		if(cnt==m){
			int ans_now=(INT_MAX);
			for(int i=1;i<=n;i++){
				if(use[i]==1){
					ans_now&=a[i];
				}
			}
			ans=max(ans,ans_now);
		}
		return;
	}
	use[now]=0;
	dfs(now+1,cnt);
	use[now]=1;
	dfs(now+1,cnt+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(0)cout<<1;
	if(n<=20){
		dfs(1,0);
		cout<<ans;
	}
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			cout<<ans;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		if(m==n){
			ans=INT_MAX;
			for(int i=1;i<=n;i++){
				ans&=a[i];
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){//二进制拆分 
			int now=a[i];
			while(now){
				if(now%2==0){
					ejz[i]="0"+ejz[i];
				}
				else{
					ejz[i]="1"+ejz[i];
				}
				now/=2;
			}
			sz_mx=max(sz_mx,int(ejz[i].size()));
		} 
		for(int i=1;i<=n;i++){//对齐,不足补0 
			while(ejz[i].size()<sz_mx){
				ejz[i]="0"+ejz[i];
			}
		}
		for(int i=1;i<=n;i++){
			vis[i]=1;
		}
		for(int i=0;i<sz_mx;i++){//求答案每一二进制位是否为1,从高位到低位 
			int cont1=0;
			for(int j=1;j<=n;j++){
				if(ejz[j][i]=='1' && vis[j]){
					cont1++;
				}
			}
			if(cont1>=m){
				bj[i+1]=1;
				for(int j=1;j<=n;j++){
					vis[j]=(vis[j]&&(ejz[j][i]=='1'));
				}
			}
		}
		for(int i=1;i<=sz_mx;i++){ 
			ans+=(bj[i]<<(sz_mx-i));
		}
		cout<<ans;
	}
	return 0;
}
//我蛆我出息了 想出T3正解了 
