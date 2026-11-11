#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m,a[N],b[N]={N,0},f[N],c;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m>0){
		for(long long i=1;i<n;i++){
			b[i]=a[i+1]-a[i];
		}
		for(long long i=1;i<=n;i++){
			if(b[i]<b[i-1]){
				f[i]=1;
			}
		}
		for(long long i=n;i>=1;i--){
			
			if(f[i]==1){
				c=c+1;
				break;
			}
		}
		m--;
	}
	cout<<c;
	return 0;
}
