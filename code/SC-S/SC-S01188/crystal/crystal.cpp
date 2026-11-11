#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,sum;
long long a[5000005];
int main(){
	freopen("crystal.in","a",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==0){
		long long s=0,z;
		for(int i=1;i<=n;i++){
			long long x=0;
			if(a[i]!=-1){
				z=a[i];
				for(int i=1;i<=n;i++){
					if(a[i]==z){
						x++;
						a[i]=-1;
					}
				}
				if(x>s) s=x;
			}
		}
		cout<<s;
	}
	else{
		for(int i=n;i>=1;i--){
			if(m>=a[n]-a[i]){
				m-=a[n]-a[i];
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}