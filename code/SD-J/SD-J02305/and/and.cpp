#include <bits/stdc++.h>
using namespace std;
long long a[210000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
		long long max_1=-1;
		for(int i=1;i<=n;i++) max_1=max(max_1,a[i]);
		cout<<max_1<<endl;
		return 0;
	}
	if(m==2){
		long long max_1=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				max_1=max(max_1,x);
			}
		}
		cout<<max_1;
	}
	if(m==n-1){
		long long max_1=-1;
		for(int i=1;i<=n;i++){
			long long x=1; 
			for(int j=1;j<+n;j++){
				if(j!=i){
					x=x&a[j];
				}
			}
			max_1=max(max_1,x); 
		}
		cout<<max_1<<endl;
	}
	return 0;
}
