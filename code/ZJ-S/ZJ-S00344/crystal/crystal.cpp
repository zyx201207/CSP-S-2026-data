#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int n,m,a[N],ans;
int sum;
void px(){
	for(int i=1;i<=n;i++){
		int minn=1e13,mini;
		for(int j=i;j<=n;j++){
			if(a[j]<minn){
				minn=a[j];
				mini=j;
			}
		}
		int t=a[i];
		a[i]=a[mini];
		a[mini]=a[i];
	}
}

signed main(){
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	px();
	
	for(int i=n;i>=1;i--){
		sum=0;
		for(int j=1;j<=i;j++){
			sum+=a[i]-a[j];
		} 
		if(sum<=m){
			ans=i;
			break;
		}
	} 
	cout<<ans;
	
	return 0;
}

