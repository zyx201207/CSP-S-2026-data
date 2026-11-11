#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;a
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			bool can=false;
			ll tmp=m;
			for(int k=j;k<j+i;k++){
//				cout<<i<<' '<<j<<' '<<a[j+i-1]<<' '<<a[j]<<' '<<tmp<<'\n'; 
				if(a[j+i-1]-a[k]<=tmp){
					tmp-=a[j+i-1]-a[k];
					can=true;
				}else{
					can=false;
					break;
				}
			}
			if(can){
				ans=i;
				break;
			}
		}
	}
	cout<<ans;
}