#include<bits/stdc++.h>
using namespace std;
long long n,a[100009];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
    long long ans=0,l=1,r=n;
    
	while(l!=r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				r--;
				l++;
			}
		}
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
