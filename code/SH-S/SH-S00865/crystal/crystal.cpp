#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,sum,t,s[205];
bool c(){
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=a[i-1]-a[i-2])return 0;
	return 1;
}
void s1(){
	for(int i=n;i>=1;i--){
		t=sum=0;
		for(int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m)break;
			t++;
		}
		ans=max(t,ans);
	}
	cout<<ans;
}
void s2(){
	for(int i=1;i<=n;i++)s[a[i]+101]++;
	for(int i=201;i>=0;i--){
		t=sum=0;
		for(int j=i;j>=0;j--){
			if(sum+(i-j)*s[j]>m){
				t+=(m-sum)/(i-j);
				break;
			} 
			sum+=(i-j)*s[j];
			t+=s[j];
		}
		ans=max(ans,t);
	}
	cout<<ans;
}
void s3(){
	for(int i=1;i<=n;i++){
		if(m<i*(i-1)/2*(a[n]-a[n-1])){
			cout<<i-1;
			break;
		}
		if(i==n)cout<<n;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		s1();
	}else if(a[n]<=100&&a[1]>=-100){
		s2();
	}else if(c()){
		s3();
	}else{
		s1();
	} 
	return 0;
}
