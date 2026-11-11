#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N],cf[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
		cout<<cf[i]<<' ';
	}
	cout<<'\n';
	int sum=0;
	for(int i=1;i<=n-1;i++) sum+=a[i];
	s[n]=a[n]*(n-1)-sum;
	for(int i=n-1;i>=1;i--){
		s[i]=s[i+1]-i*cf[i+1];
	}
	for(int i=1;i<=n;i++) cout<<s[i]<<' ';
	
	int ans;
	for(int i=n;i>=1;i--){
		if(s[i]<=m){
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0;
}      
//5 8
//-3 -1 2 2 7
//0 0 0 0 0
//2 0 0 0 0
//8 3 0 0 0
//8 3 0 0 0
//28 18 10 5 0
//1 1 1 8 8 8
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//21 14 7 0 0 0
//21 14 7 0 0 0
//21 14 7 0 0 0
