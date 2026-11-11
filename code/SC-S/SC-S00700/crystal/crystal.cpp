#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
void solve1(){
	long long cnt=0,ans=0;
	for(int i=n;i>=1;i--){
		cnt+=(a[n]-a[i]);
		if(cnt<=m){
//			cout<<cnt<<'\n';
			ans++;
		}
		else{
			cout<<ans;
			return ;
		}
	}
	cout<<ans;
	return ;
}
void solve2(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long cnt=0,nans=0;
		for(int j=i;j>=1;j--){
		    cnt+=(a[i]-a[j]);
		    if(cnt<=m){
			    nans++;
    		}
	    	else{
		    	break;
		    }
    	}
    	ans=max(ans,nans);
	}
	cout<<ans;
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int delta=abs(a[2]-a[1]);
	for(int i=2;i<=n;i++){
		if(abs(a[i]-a[i-1])!=delta){
			flag=0;
		}
    } 
	if(flag==1){
		solve1();
		return 0;
	}
//	if(n<=5000){
		solve2();
		return 0;
//	}
	return 0;
}