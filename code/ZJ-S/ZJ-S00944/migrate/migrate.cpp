//RP++
#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
long long n,d;
long long f(int a,int b){
	long long now=a,res=0,lst=-1;
	while(now<b){
		now=upper_bound(x+1,x+1+n,x[now]+d)-x-1;
		if(now==lst)return -1;
		lst=now;
		++res;
	}
	return res;
}
int check(int a,int b){
	if(x[a]+d>=x[b])return 0;
	else{
		int cc=upper_bound(x+1,x+1+n,x[a]+d)-x-1;
		if(cc<=0)return 0;
		int ccc=cc-1;
		long long fc=f(cc,b);
		if(fc==-1)return 0;
		if(ccc<=0)return check(cc,b);
		long long fcc=f(ccc,b);
		if(fc!=fcc)return check(cc,b);
		int cccc=ccc-1;
		if(cccc<=0)return 1;
		long long fccc=f(cccc,b);
		if(fccc!=fcc){
			return 1;
		}else return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans+=check(i,j);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
