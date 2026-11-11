#include<bits/stdc++.h>
using namespace std;
int n,k,a[2000010],f[2000010];
void dfs(int x){
	if(x>n) return ;
	f[x]++;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=k) dfs(i);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			int f=a[2]-a[1];
			if(k<2*f||k>=3*f){
				cout<<0<<"\n";
				continue;
			}
			for(int i=2;i<=n-1;i++){
				if((i*f)%k!=0) cnt+=(n-i);
			}
			cout<<cnt<<"\n";
		}
		if(c==1||c==2){
			for(int i=1;i<=n;i++){
				dfs(i);
				for(int j=1;j<=n;j++){
					cout<<f[j]<<" ";
					if(f[j]==2&&i!=j&&abs(a[j]-a[i])>=k) cnt++;
				}
				memset(f,0,sizeof f);
				cout<<"\n";
			}
			
			cout<<cnt<<"\n";
		}
	}
	return 0;
}

