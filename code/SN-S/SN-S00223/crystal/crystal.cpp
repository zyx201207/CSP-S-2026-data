#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],ans=-1,use;
bool flag=true;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=false;
		break;
	}
	if(flag){
		int z=m/abs(a[2]-a[1]);
		 if(z==1)ans=2;
		else if(z==3)ans=3;
		else if(z==6)ans=4;
		else ans=(int)(sqrt(2*z+0.25)-0.5-0.01)+1;
		ans=min(ans,n);
	}
	else {
		sort(a+1,a+n+1,cmp);
		for(long long i=1;i<=n;i++){
			long long num=1;
			use=0;
			for(long long j=i+1;j<=n;j++){
				use+=a[i]-a[j];
				if(use>m) break;
				num++;
			}
			ans=max(ans,num);
		}
}
	cout<<ans;
	
	
	return 0;
}

 
