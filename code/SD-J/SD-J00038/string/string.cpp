#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],l=1,r,sum=0;
char b[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(l<r){
		if(b[l]==b[r]){//×ÖÄ¸ÏàÍ¬ 
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]==a[r]){
				sum+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
