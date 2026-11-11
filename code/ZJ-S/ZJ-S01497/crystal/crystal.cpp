#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans,maxx,f[210];
bool flag1=1,flag2=1;
int check(int t){
	int now=0;
	for(int i=t-1;i>=1;i--){
		if(now+(a[t]-a[i])<=m){
			now+=(a[t]-a[i]);
		}else{
			return t-i;
		}
	}
	return t;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,abs(a[i]));
		if(a[i]!=i)flag1=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])flag2=0;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			ans=max(ans,check(i));
		}
		cout<<ans;
	}else if(maxx<=100){
		for(int i=1;i<=n;i++){
			f[a[i]+100]++;
		}
		for(int i=0;i<=200;i++){
			int now=i-1,cnt=0,tmp=m;
			while(now>=0&&tmp>0){
				if(f[now]*(i-now)<=tmp){
					tmp-=f[now]*(i-now);
					cnt+=f[now];
				}else{
					cnt+=tmp/(i-now);
					tmp=0;
					break;
				}
				now--;
			}
			ans=max(ans,cnt+f[i]);
		}
		cout<<ans;
	}else if(flag1){
		int now=0;
		for(int i=1;i<=n;i++){
			if(now+i<=m){
				now+=i;
			}else{
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}else if(flag2){
		int now=0,d=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(now+i<=m){
				now+=i*d;
			}else{
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}
	return 0;
}
