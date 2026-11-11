#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
猫猫我啊
最近知道了一个事情
就是蝴蝶阿姨的射箭技术没有心夏阿姨厉害
为什么呢?
原来啊
蝴蝶阿姨胸前有两个障碍物
一拉弓弦
就会打到自己
而心夏阿姨呢
就不会有这种问题了呢
awa 
*/ 
int n,m;
int a[7210721];
bool ok,fx;
int sml=11451419;
void dfs(int s,int f,int no,int t){
	if(fx)return ;
	if(f==no){
		if(t>sml)return ;
		if(t<sml){
			sml=t;
			ok=0;
			return ;
		} 
		if(t==sml){
			if(ok==1){
				fx=1;
				ok=0;
				return;
				
			}
			ok=1;
			return;
		}
	}
	for(int i=no+1;i<=f;i++){
		if(a[i]-a[no]<=m){
			dfs(s,f,i,t+1);
			
		}
		else return;
	}
}
signed main(){
	 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				dfs(i,j,i,0);
				if(ok){
					ans++;
					ok=0;
					sml=11451419;
					fx=0;
				}
			}
		}
		cout<<ans<<endl;
	}
} 
