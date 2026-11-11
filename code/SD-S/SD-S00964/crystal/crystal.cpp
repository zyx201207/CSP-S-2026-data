#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
long long n,a[N],m,m1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=1;
		}
	}
	sort(a+1,a+1+n);
	if(flag==1){
		long long ans=1,cnt=1,l,r;
		for(int i=2;i<=n;i++){
			m1=m,cnt=1;
			for(int j=i-1;j>=1;j--){
				if(m1-(a[i]-a[j])>=0){
					m1=m1-(a[i]-a[j]);
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}else{
		long long bc,ans=0,x;
		bc=abs(a[2]-a[1]);
		while(true){
			x=1;
			if(m-bc*x>=0){
				m=m-bc*x;
				ans++;
				if(ans>=n){
					break;
				}
			}else{
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}


