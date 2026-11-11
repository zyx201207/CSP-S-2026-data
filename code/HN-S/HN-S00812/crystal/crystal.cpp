#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans=0,zans=-999999;
long long w=0;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		w+=i*(a[i]-a[i-1]);
		if(m>=w){
			ans++;
			zans=max(ans,zans);
		}else{
			int g=0;
			while(w-a[i]+a[g]<m){
				g++;
				ans--;
			}
		}
	}
	cout<<zans;
	return 0;
}
