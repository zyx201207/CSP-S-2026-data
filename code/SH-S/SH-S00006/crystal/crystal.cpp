#include<bits/stdc++.h>
using namespace std;
bool cyd(long long a,long long b){
	return a>b;
}
int n;
long long m,a[500005],ans,m1,ans1,b[500005];
bool ff=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		b[i]=abs(a[i+1]-a[i]);
		if(i>1&&b[i]!=b[i-1]) ff=false;
	}
	if(!ff){
		sort(a+1,a+n+1,cyd);
		for(int i=1;i<=n;i++){
			ans1=0;
			m1=m;
			for(int j=i+1;j<=n;j++){
				if(m1>=a[i]-a[j]){
					m1-=a[i]-a[j];
					ans1++;
				}
				if(m1==0) break;
			}
			ans=max(ans,ans1+1);
			if(ans>=n-i+1) break;
		}
	}
	else{
		int u=0;
		while(1){
			u++;
			if(m>=u*a[1]){
				m-=u*a[1];
				ans++;
			}
			else break;
		}
		ans++; 
	}
	cout<<ans;
	return 0;
} 
