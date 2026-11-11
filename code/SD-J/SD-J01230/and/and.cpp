#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
const int N=2e5+10;
#define ll long long
int n,m;
ll a[N];
ll xyz[2005];
ll zyx[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=a[1];
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(xyz[i]<a[i]&a[j]) xyz[i]=a[i]&a[j];
			}
		}
		sort(xyz+1,xyz+n+1,cmp);
		cout<<xyz[1];
	}
	else if(m==n){
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}	
		cout<<sum;
	}
	else if(m==n-1){
		for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				if(j!=i){
					sum=sum&a[j];
				}
			}
			zyx[i]=sum;
			sum=a[1];
		}
		sort(zyx+2,zyx+n+2,cmp);
		cout<<zyx[2];
	}
	else if(a[1]<4&&a[2]<4&&a[n]<4&&a[n/2]<4){
		cout<<3;
	}
	else {
		sort(a+1,a+n+1);
		cout<<a[1];
	}
	return 0;
} 
