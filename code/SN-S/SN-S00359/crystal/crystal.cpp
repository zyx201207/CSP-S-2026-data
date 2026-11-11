//SN-S00359 张馨月 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],d[500005];
long long ans=1;
bool dc=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=0;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(dc&&i>2&&d[i]!=d[i-1]) dc=false;
	}
	if(dc){
		long long x=d[2];
		long long summ=0;
		while(summ<m){
			summ+=x;
			x+=d[1];
			ans++;
		}
		//cout<<sum<<" "<<ans<<endl;
		if(summ==m){
			if(ans>n) cout<<n;
			else cout<<ans;
		}
		else{
			if(ans>n) cout<<n;
			else cout<<ans-1;
		}
		return 0;
	}
	else{
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long sum=0;
				for(int k=1;k<=j-i;k++){
					sum+=k*d[i+k];
					if(sum>m){
						break;
					}
				}
				if(sum<=m){
					ans=max(ans,(j-i+1)*1ll);
				}
			}
		}
	}
	
	cout<<ans;
	
	
	
	return 0;
}
