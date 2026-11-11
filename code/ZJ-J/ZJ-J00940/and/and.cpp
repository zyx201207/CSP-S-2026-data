#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m;
int a[N];
int dp[25][25];
int ans1,ans2;
void solve1(){
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=2;k<=i;k++){
				dp[i][k]=max(dp[i][k],dp[j][k-1]&a[i]);
			}
		}
	}
	cout<<dp[n][m]<<'\n';
	return ;	
}
void solve2(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			sum=max(sum,a[i]&a[j]);
		}
	}
	cout<<sum<<'\n';
}
void solve3(){
	int cnt4=0,cnt3=0,cnt2=0,cnt1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==4) cnt4++;
		else if(a[i]==3) cnt3++;
		else if(a[i]==2) cnt2++;
		else cnt1++;
	}
	if(cnt4>=m) cout<<"4"<<'\n';
	else if(cnt3>=m){
		cout<<"3"<<'\n';
	}
	else if(cnt3+cnt2>=m){
		cout<<"2"<<'\n';
	}
	else if(cnt3+cnt1>=m){
		cout<<"1"<<'\n';
	}
	else{
		cout<<"0"<<'\n';
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans1=max(ans1,a[i]);
		if(i==1) ans2=a[i];
		else ans2=ans2&a[i];
	}
	if(n<=20){
		solve1();
	}
	else if(n<=2000){
		if(m==1){
			cout<<ans1<<'\n';
		}
		else if(m==n){
			cout<<ans2<<'\n';
		}
		else if(m==2){
			solve2();
		}
	}
	else if(ans1<=4){
		solve3();
	}
	else{
		cout<<"0"<<'\n';
	}
	return 0;
}
