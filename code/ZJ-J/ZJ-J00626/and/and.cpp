#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200005];
ll zdz=0;
void dfs(int wz,ll sum,int sl){
	//cout<<wz<<' '<<sum<<' '<<sl<<' '<<zdz<<'\n';
	if(sl>=m){
		zdz=max(zdz,sum);
		return;
	}
	if(n-wz+sl+1<m||sum<=zdz||wz>n)return;
	dfs(wz+1,sum&a[wz],sl+1);
	dfs(wz+1,sum,sl);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=a[i]+1;
		if(f){
			while(j%2==0){
				//cout<<j<<'\n';
				j/=2;
			}
			if(j!=1){
				f=0;
			}
		}
	}
	
	if(n==m){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			zdz=max(zdz,a[i]);
		}
		cout<<zdz;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			dfs(i+1,a[i],1);
		}
		cout<<zdz;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				zdz=max(zdz,a[i]&a[j]);
			}
		}
		cout<<zdz;
		return 0;
	}
	if(f){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	
		int bx=n-m;
		ll fy[n+2],by[n+2];
		fy[1]=a[1];by[n]=a[n];
		for(int i=2;i<=n;i++)fy[i]=fy[i-1]&a[i];
		for(int i=n-1;i>=1;i--)by[i]=by[i+1]&a[i];
		for(int i=bx;i<=n-bx+1;i++){
			if(i==bx){
				zdz=max(zdz,by[1+bx]);
			}else if(i==n-bx+1){
				zdz=max(zdz,fy[n-bx]);
			}else{
				zdz=max(zdz,fy[i-bx]&by[i+bx]);
			}
		}
		cout<<zdz;
	
	return 0;
}