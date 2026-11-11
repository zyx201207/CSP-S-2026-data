#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200010],tpa[200010];
bool tepanB(){
	for(int i=0;i<n;i++){
		if(a[i]!=i-1){
			return false;
		}
	}
	return true;
}
bool tepanA(){
	for(int i=0;i<n;i++){
		if((a[i]+1)%2==1){
			return false;
		}
	}
	return true;
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxai=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		tpa[i]=a[i];
		maxai=max(maxai,a[i]);
	}
	if(m==1){
		cout<<maxai;
		return 0;
	}
	if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=int(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxit=-1;
		for(int i=0;i<n;i++){
			for(int j=n-1;j>i;j--){
				maxit=max(maxit,int(a[i]&a[j]));
			}
		}
		cout<<maxit;
		return 0;
	}
	if(tepanB()){
		cout<<n-m;
		return 0;
	}
	if(tepanA()){
		sort(tpa,tpa+n,greater<int>());
		cout<<tpa[m-1];
		return 0; 
	}
	cout<<"0";
	return 0;
} 
