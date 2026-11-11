#include<bits/stdc++.h>
using namespace std;
const long long inf=0x7fffffff;
long long maxn=-inf;
int i,j,k;
int c,t;
int n,d;
int x[2000002];
int mark[2000002];
int diff[2000002];
int u,v;
int sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		sum=0;
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>x[i];
			mark[i]=0;
		}
		diff[1]=0;
		for(i=2;i<=n;i++){
			diff[i]=x[i]-x[i-1];
		}
		for(i=1;i<=n;i++){
			j=1;
			while(diff[i]+diff[i+j]<u && i+j<=n){
				mark[i]++;
				j++;
			}
		}
		for(i=3;i<=n;i++){
			if(x[n]-x[n-2]<=d){
				sum++;
			}
		}
		
		cout<<sum-1;
		t--;
	}
	return 0;
}
