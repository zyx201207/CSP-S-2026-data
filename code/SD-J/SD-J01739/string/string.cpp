#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=min(a[r],a[l]);
				a[l]-=a[r];
				
				r--;
			}
			else{
				ans+=min(a[r],a[l]);
				a[r]-=a[l];
				
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
