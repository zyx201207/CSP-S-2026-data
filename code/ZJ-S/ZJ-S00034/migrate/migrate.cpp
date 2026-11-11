#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000005],mp[505][505],cnt[505][505];
int read(){
	int num=0;
	char c;
	while((c=getchar())&&'0'<=c&&c<='9'){
		num=num*10+(c-'0');
	}
	return num;
}
int count(int b,int step,int sum,int tgt){
	if(sum>tgt) return 0;
	if(b==step) return 1;
	int sums=0;
	for(int i=1;i<=n;i++){
		if(mp[step][i]==1){
			sums+=count(b,i,sum+1,tgt);
		}
	}
	return sums;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12||c==0){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			cout<<(d/abs(a[2]-a[1])>1?max(n-d/abs(a[2]-a[1])*2+1,0ll):0)<<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		memset(cnt,0,sizeof(cnt));
		memset(mp,0x3f3f3f3f,sizeof(mp));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[j]-a[i])<=d){
					mp[i][j]=1;
				}
			}
			mp[i][i]=0;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(mp[i][j]>mp[i][k]+mp[k][j]){
						mp[i][j]=mp[i][k]+mp[k][j];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(mp[i][j]!=0x3f3f3f3f3f3f3f3f&&count(j,i,0,mp[i][j])==2){
					++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
