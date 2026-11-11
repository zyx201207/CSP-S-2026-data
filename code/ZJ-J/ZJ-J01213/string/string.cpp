#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200010],b[200010],sum;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r){
		if(s[r]!=s[l]){
			if(a[r]<a[l]){
				sum+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[r]==a[l]){
				sum+=a[r];
				a[r]=0,a[l]=0;
				l++;
				r--;
				
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
				
			}
		}
		else{
			if(a[r]<a[l]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[r]==a[l]){
				a[r]=0,a[l]=0;
				l++;
				r--;
			}
			else{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
