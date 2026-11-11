#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,t,k;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}long long l=1,r=1;
	while(r!=n+1){
		if(b[r]-b[l]-(l-1)*(a[r]-a[l])>m){
			l++;
		}else{
			r++;
		}
		ans=max(r-l,ans);
	}cout<<ans;
	return 0;
}