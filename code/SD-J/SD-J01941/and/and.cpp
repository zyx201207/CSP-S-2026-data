#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ma=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	int ans=a[0];
	if(n==m){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<ma;
		return 0; 
	}
	long long res=pow(2,n),nma=-1;
	for(long long i=1;i<=res;i++){
		long long cnt=0,sum=0;
		for(int j=0;j<=n;j++){
			if(i&(1<<j)){
				if(cnt==0){
					cnt++;
					sum=a[j+1];
				}
				else{
					cnt++;
					sum&=a[j+1];
				}
			}
		}
		if(cnt==m){
			nma=max(sum,nma);
		}
	}
	cout<<nma;
	return 0;
}
