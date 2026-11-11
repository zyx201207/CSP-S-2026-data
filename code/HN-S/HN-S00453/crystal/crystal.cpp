#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=1e5;
long long n,m;
long long a[N],s[N],sum[N],ans;
void far(int k){
	for(int i=1;i<k;i++){
		for(int j=i+1;j<=k;j++) sum[k]+=s[j];
	}
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]-a[i-1];
		far(i);
	}
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(sum[i]-sum[j]<=m) ans=max(ans,(long long)i-j+1);
		}
	}
	cout<<ans;
	return 0;
}
