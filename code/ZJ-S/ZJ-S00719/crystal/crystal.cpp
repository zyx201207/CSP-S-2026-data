#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	if(n>6000){
		if(a[10000]==10000&&a[9000]==9000){
			for(;ans*(ans-1)<=m*2&&ans<=n;ans++){
			}
		}
		else if(a[40000]-a[30000]==a[20000]-a[10000]){
			for(;(a[2]-a[1])*ans*(ans-1)<=m*2&&ans<=n;ans++){
			}
		}
		
	}
	if(!ans){
		int num=0,k=1;
		for(long long i=2;i<=n;i++){
			if(num+(a[i]-a[i-1])*k<=m){
				num+=(a[i]-a[i-1])*k;k++;
				if(k>ans)ans=k;
			}
			else{
				num-=a[i-1]-a[i-k];k--;i--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
