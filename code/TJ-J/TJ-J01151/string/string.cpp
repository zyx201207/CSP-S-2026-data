#include<bits/stdc++.h>
using namespace std;
struct zcm{
	long long n;
	char z;
}a[1000005];
long long sum,sum1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].n>>a[i].z;
	}
	int l=1,r=n;
	while(l<r){
		if(l-1==r) break;
		if(a[l].z==a[l+1].z){
			a[l+1].n+=a[l].n;
			l++;
			continue;
		}
		if(a[r].z==a[r-1].z){
			a[r-1].n+=a[r].n;
			r--;
			continue;
		}
		if(a[l].n<0){
			a[l+1].n+=a[l].n;
			l++;
			continue;
		}
		if(a[r].n<0){
			a[r-1].n+=a[r].n;
			r--;
			continue;
		}
		if(a[l].z==a[r].z){
			long long x=abs(a[r].n-a[l].n);
			if(a[l].n<a[r].n){
				a[l].n+=x;
				sum+=x;
				a[l+1].n-=x;
				l++;
				r--;
			}else if(a[l].n>a[r].n){
				a[r].n+=x;
				sum+=x;
				a[r-1].n-=x;
				l++;
				r--;
			}else{
				l++;
				r--;
			}
		}else if(a[l].z!=a[r].z){
			long long x=abs(a[r].n-a[l].n);
			if(a[l].n<a[r].n){
				a[l].n+=x;
				if(a[l+1].z==a[r].z){
					sum+=a[l].n-x;
					l++;
				}else{
					sum+=a[l].n;
					a[l+1].n-=x;
				}
				l++;
				r--;
			}else if(a[l].n>a[r].n){
				a[r].n+=x;
				if(a[r-1].z==a[l].z){
					sum+=a[r].n-x;
					r--;
				}else{
					sum+=a[r].n;
					a[r-1].n-=x;
				}
				l++;
				r--;
			}else{
				sum+=a[l].n;
				l++;
				r--;
			}
		}
	}
	cout<<sum;
} 
