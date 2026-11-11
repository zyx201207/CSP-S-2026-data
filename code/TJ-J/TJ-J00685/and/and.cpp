#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,a[N],pow2[N],ans=-2e9,b[N];
void dg(int step,int cnt,int sum){
	if(cnt>m) return;
	if(step==n+1&&cnt<m) return;
	if(step==n+1&&cnt==m){
		ans=max(ans,sum);
		return;
	}
	b[step]=0;
	dg(step+1,cnt,sum);
	b[step]=1;
	dg(step+1,cnt+1,sum&a[step]);
}
bool check1(){
	for(int i=1;i<=n;i++){
		bool flag=false;
		for(int j=1;j<=30;j++){
			if(pow2[j]==a[i]+1){
				flag=true;
				break;
			}
		}
		if(!flag) return false;
	}
	return true;
}
bool check2(){
	bool flag=false;
	for(int i=1;i<=30;i++){
		if(n==pow2[i]){
			flag=true;
			break;
		}
	}
	if(!flag) return false;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	pow2[0]=1;
	for(int i=1;i<=30;i++) pow2[i]=pow2[i-1]*2;
	if(check1()||check2()){
		int x=a[n]&a[n-1];
		cout<<x;
	}
	else if(m==1){
		cout<<a[n];
	}
	else if(m==2){
		int sum=-2e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(a[i]&a[j],sum);
			}
		}
		cout<<sum;
	}
	else if(m==n){
		int sum=a[1];
		for(int i=1;i<=n;i++) sum&=a[i];
		cout<<sum;
	}
	else if(m==n-1){
		int sum1=a[2],sum2=a[1];
		for(int i=2;i<=n;i++) sum1&=a[i];
		for(int i=1;i<=n-1;i++) sum2&=a[i];
		cout<<max(sum1,sum2);
	}
	else{
		dg(1,0,pow2[30]-1);
		cout<<ans;
	}
	return 0;
}
