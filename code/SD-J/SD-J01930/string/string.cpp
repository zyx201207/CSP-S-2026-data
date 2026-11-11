#include<bits/stdc++.h> 
using namespace std;
long long n,sum,ans;
long long a[300007];
char c[300007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		
		if(c[l]==c[r]){
			if(a[l]<=a[r]){
				a[r]-=a[l];
				l++;
			}
			else {
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]<=a[r]){
				a[r]-=a[l];
				sum+=a[l];
				l++;
			}
			else {
				a[l]-=a[r];
				sum+=a[r];
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
