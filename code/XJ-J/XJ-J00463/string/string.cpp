#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[200005]={};
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int r=1,l=n;
	long long sum=0;
	while(1){
		if(r==l ||r>l) break;
		if(a[r]>a[l]){
			if(c[r]!=c[l]) sum+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l--;
		}
		else {
			if(c[r]!=c[l]) sum+=a[r];
			a[l]-=a[r];
			a[r]=0;
			if(a[l]==0) l--;
			r++;
		}
		
	}
	cout<<sum;
	return 0;
}