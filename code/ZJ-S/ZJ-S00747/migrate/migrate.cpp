#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,x[2000050],minn,ans;
long long f(int i,int j){
	if(abs(x[i]-x[j])<=d)return 1;
	if(abs(x[i]-x[j])>=2*d)return 1;
	return 2;
}
void solve(long long n,long long d){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f(i,j)==2)ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		minn=0x3f3f3f;
		solve(n,d);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}