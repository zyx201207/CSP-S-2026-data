#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool dcsl=true;
	int gc=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=gc) dcsl=false;
	}
	if(dcsl){
		int gch=0;
		int gcs=0;
		while(gch<=m){
			gcs++;
			gch+=gcs*gc;
		}
		cout<<gcs;
		return 0;
	}
	for(int i=1;i<n;i++){
		long long s=0;
		for(int j=i+1;j<=n;j++){
			s+=(a[j]-a[j-1])*(j-i);
			if(s>m){
				ans=max(ans,j-i);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
