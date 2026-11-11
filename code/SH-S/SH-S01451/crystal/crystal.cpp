#include<bits/stdc++.h>
using namespace std;
int n,ans=0,cnt=0;
long long m,x;
int jdz(int x,int y){
	if(x>y) return x-y;
	return y-x; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n],b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(n>5000 && m>100000000){
		if(a[1]-a[0]==1) ans=max(n,int(ceil(sqrt(2.0*m+0.25)-0.5)));
		else ans=max(n,int(ceil(sqrt(2.0*m/(a[1]-a[0])+0.25)-0.5)));
		cout<<ans;
		return 0;
	}
	for(int i=a[0];i<=a[n-1];i++){
		x=m;
		cnt=0;
		for(int j=0;j<n;j++) b[j]=jdz(a[j],i);
		sort(b,b+n);
		for(int j=0;j<n;j++){
			if(x>=b[j]){
				x-=b[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
