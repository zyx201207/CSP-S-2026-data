#include<bits/stdc++.h>
using namespace std;
int n;                       
long long m,a[500010],tot,minn=8446744073709551617,mini,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	tot=m;
	for (int i=0;i<n;++i){
		cin>>a[i];
		tot+=a[i];
	}
	tot/=n;
	for (int i=0;i<n;++i){
		if (tot-a[i]<minn&&tot-a[i]>=0){
			minn=tot-a[i];
			mini=a[i];
		}
	}
	for (int i=0;i<n;++i){
		if (a[i]<=mini){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
