#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],f=1,xc=2;
bool ccc(int s){
	while(s){
		if(s%xc==0)return 0;
		s/=2;
	}return 1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ccc(a[i])==0){
			f=0;
		}
	}if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}cout<<ma;
		return 0;
	}if(m==n){
		int ans=1048575;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}cout<<ans;
		return 0;
	}if(f==1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}cout<<ma;
		return 0;
	}
	return 0;
}
