#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,t,n,d,cnt,ans;
int a[305],b[305];
map<int,int> mp;
void dfs(){
	bool flag=0;
	mp.clear();
	for(int mask=1;mask<(1<<cnt);mask++){
		int c=0,x=0;
		bool f1=0,f2=0,f3=1;
		for(int i=0;i<cnt;i++){
			if(mask&(1<<i)){
				c++;
				if(i==0){
					f1=1;
					x=b[cnt];
					continue;
				} 
				if(i==cnt-1) f2=1;
				if(abs(b[cnt-i+1]-x)>d) f3=0;
				x=b[i];
			}
		}
		if(f1==1 && f2==1 && f3==1 && c>=3) mp[c]++;
	}
	for(int i=3;i<=305;i++){
		if(mp[i]==2 && flag==0){
			ans++;
			break;
		}
		if(mp[i]!=0) flag=1;
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){	
			for(int j=i+3;j<=n;j++){
				cnt=0;
				for(int k=i;k<=j;k++) b[++cnt]=k;
				dfs();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
