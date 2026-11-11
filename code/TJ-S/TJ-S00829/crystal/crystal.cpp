#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long sum[N],a[N];
long long n,m;
void solve1(){
	long long  x;
	for(int i=1;i<=n;i++){
		if(i%2==0) x=i/2*(i-1);
		else x=(i-1)/2*i;
		//x=i*(i-1)/2;
		if(x>m) {
			//cout<<x;
			cout<<i-1;
			return ;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fa=1,fb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) fa=0;
	}
	if(fa==1){
		solve1();
		return 0;
	}
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int y=j-i+1;
			int x=a[j]*y-(sum[j]-sum[i-1]);
			if(x<=m){
				ans=max(ans,y);
				
			}
		}
	}
	cout<<ans;
	return 0;
}
