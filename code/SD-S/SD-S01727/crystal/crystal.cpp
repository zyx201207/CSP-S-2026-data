#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
long long m;
long long a[500005];
long long dis[500005];
long long sum[500005];
int cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i]; 
		dis[i]=a[i]*(i-1)-sum[i-1];	
	}
	sort(dis+1,dis+n+1);
	for(int i=n;i>=1;i--){
		if(dis[i]<=m){
			for(int j=i;j>=1;j--){
				if(m<a[i]-a[j]) break;
				m-=a[i]-a[j];
				cnt++;
			}
			cout<<cnt;
			return 0;
		}
	}
	cout<<0;
	return 0; 
}  
