#include<bits/stdc++.h>
using namespace std;
const int N=100010;
long long int a[N],f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,maxs=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long int b=a[i];
		long long int c=m;
		for(int j=1;j!=i &&j<=n;j++){
			for(int k=1;k<=n;k++){
				f[k]=0;
			}
			for(int k=j;k!=i && k<=n;k++){
				if(a[k]<=a[i] && a[i]-a[k]<=c){
				c-=a[i]-a[k];
				a[k]=a[i];
				f[k]=1;
				}
			}
			long long int cnt=1;	
			for(int k=1;k<=n;k++){
				if(f[k]==1){
					cnt++;
				}
				maxs=max(maxs,cnt);
			}
		}
	}
	cout<<maxs;
	return 0; 
}
