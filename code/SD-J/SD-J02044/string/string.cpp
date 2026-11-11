#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long a[maxn];
string b[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else{
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}
			else{
				ans+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
