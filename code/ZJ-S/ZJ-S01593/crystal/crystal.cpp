#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans,ma,f1=1,f2=0,d;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],ma=max(abs(a[i]),ma);
		if(a[i]!=i) f1=0;
		if(i==2) d=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]==d) f2=1;
	}
	if(f1==1){
		int cnt=0,k=1;
		while(m-k>=0&&k<=(n+1)/2-1){
			m-=k,cnt++;
			if(cnt%2==0) k++;
		}
		if(m>=k&&n%2==0) cnt++;
		cout<<cnt+1;
	}
	if(f2==1){
		int cnt=0,k=d;
		while(m-k>=0&&k<=a[(n+1)/2]-a[1]){
			m-=k,cnt++;
			if(cnt%2==0) k+=d;
		}
		if(m>=k&&n%2==0) cnt++;
		cout<<cnt+1;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=-1*ma;i<=ma;i++){
			int sum=0,cnt=0;
			for(int j=1;j<=n;j++) b[j]=abs(a[j]-i);
			sort(b+1,b+n+1);
			for(int j=1;j<=n;j++){
				if(sum+b[j]<=m) cnt++,sum+=b[j];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
}
