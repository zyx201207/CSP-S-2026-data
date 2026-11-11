#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
bool A(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i)return 0;
	}
	return 1;
}
bool B(){
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)cout<<a[i]<<'\n';
	if(m==0){
		cout<<0<<'\n';
		return 0;
	}
	if(A()){
		long long i;
		if(m==1){
			cout<<2<<'\n';
			return 0;
		}
		for(i=1;i*(i+1)<=2*m;i++);
		cout<<i<<'\n';
		return 0;
	}
	if(B()){
		long long p=abs(a[2]-a[1]);
		if(m<p){
			cout<<0<<'\n';
			return 0;
		}
		long long i;
		for(i=1;i*(i+1)*p<=2*m;i++);
		cout<<i<<'\n';
		return 0;
	}
//	if(n<=5000){
		long long ans=0;
		for(int i=2;i<=n;i++){
			long long k=0,cnt=1;
			int flag=1;
			for(int j=i-1;j>=1;j--){
				k+=abs(a[i]-a[j]);
//				cout<<j<<'\n';
//				cout<<k<<' ';
//				cout<<m<<'\n';
				if(k>m){
//					cout<<"i-1:"<<i-1<<"j:"<<j<<"k:"<<k<<"m:"<<m<<"cnt:"<<cnt<<'\n';
					ans=max(ans,cnt);
					flag=0;
					break;
				}
				cnt++;
			}
			if(flag)ans=max(ans,cnt);
		}
		cout<<ans<<'\n';
//	}
	return 0;
}
/*
5 5 
1 2 4 8 9
*/
