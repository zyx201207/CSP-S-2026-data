#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
long long a[N],st[N],s[N],t[N],u[N],p[N];
unsigned long long b[N];
int main(){
	long long n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		st[i]=a[i+1]-a[i];  //统计差 
	}
	st[n]=0;  //防止负数 
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+st[i];  //统计差的和 
	}
	for(int i=1;i<=n;i++){
		u[i]=u[i-1]+s[i];
	}
	int mx=0;
	for(int i=1,j=2;i<=n&&j<=n;i++){
		while((u[j]-u[i-1]-s[j+1]*(j-i+1))<=m&&j<=n){
			j++;
		}
		mx=max(mx,j-i+1);
	}
	cout<<mx;
	return 0;
}
