#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a[60001];
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
//	int f=0;
//	for(int i=0;i<=n-1;i++){
//		if(a[i]==1){
//			f+=1;
//		}
//		if(a[i]==2){
//			f+=1;
//		}
//		if(a[i]==4){
//			f+=1;
//		} 
//		if(a[i]==8){
//			f+=1;
//		}
//	}
//	if(f==3){
//		cout<<3;
//	}
//	else{
		long long maxk=0;
		for(int i=0;i<=n-2;i++){
			long long k=1,z=m;
			for(int j=i+1;j<=n-1;j++){
				if(a[i]-a[j]<=z && j!=n-1){
					k++;
					z-=(a[i]-a[j]);	
				}
				else if(a[i]-a[j]<=z && j==n-1){
					k++;
					z-=(a[i]-a[j]);	
					maxk=max(maxk,k);
					break;
				}
				else {
					maxk=max(maxk,k);
					break;
				}
			}		
		}
		cout<<maxk;
//	}
	return 0;
}