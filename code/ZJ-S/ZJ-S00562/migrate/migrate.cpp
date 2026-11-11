#include<bits/stdc++.h>
using namespace std;
int f[2000009],n,d,a[2000009],ans,c,t;
long long dp(int x,int y){
	f[x]=1;
	for(int i=x+1;i<=y;i++){
		f[i]=0;
		for(int j=x;j<i;j++){
			if(a[i]-d<=a[j])f[i]+=f[j];
		}
	}
	return f[y];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;i++){
				if(dp(i,j)==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
}