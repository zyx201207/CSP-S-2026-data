#include<bits/stdc++.h>
using namespace std;
long long m,n,a[10000001];
long long ans=0;
bool b[10000001];
void inline solve(long long sum,int i){
	if(i==0){
		ans=max(ans,sum);
		return;
	}
	for(int j=1;j<=n;j++){
		if(b[j]==1){
			continue;
		}
		int jj=sum;
		sum=sum&a[j];b[j]=1;
		solve(sum,i-1);
		sum=jj,b[j]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else
	if(m==1){
		sort(a+1,a+n+1);ans=a[n];
		cout<<ans;
	}
	else if(m==2){
		long long ma=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				ma=max(ans,ma);
			}
		}
		cout<<ma;
	}
	else if(m<=20){
		for(int i=1;i<=n;i++){
			b[i]=1;
			solve(a[i],m-1);
			b[i]=0;
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);ans=a[n];
		for(int i=2;i<=m;i++){
			ans=ans&a[n-i+1];
		}
		cout<<ans;
	}
}
