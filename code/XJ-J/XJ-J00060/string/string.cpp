#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
long long sum;
char z[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>z[i];
	for(int l=1,r=n;l<=r;){
		if(z[l]!=z[r]){
			sum+=min(a[l],a[r]);	
		}
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
} 
