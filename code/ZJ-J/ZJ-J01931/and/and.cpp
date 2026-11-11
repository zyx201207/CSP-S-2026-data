#include<bits/stdc++.h>
using namespace std;
long long a[200003][33],f[200003],e[33]={1},m,n,t=0,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long o,j=0;
		cin>>o;
		while(o>0){
			j++;
			a[i][j]=o%2;
			o/=2;
		}
		t=max(t,j);
	}
	for(long long i=1;i<=t;i++){
		e[i]=e[i-1]*2;
	}
	for(long long i=t;i>=1;i--){
		long long s=0;
		for(long long j=1;j<=n;j++){
			if(f[j]==0){
				s+=a[j][i];
			}
		}
		if(s>=m){
			for(long long j=1;j<=n;j++){
				if(a[j][i]==0){
					f[j]=1;
				}
			}
			ans+=e[i-1];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}