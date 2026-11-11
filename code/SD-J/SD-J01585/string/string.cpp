#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long cnt=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else{
				cnt+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
		else{
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
	}
	cout<<cnt;
	return 0;
}
