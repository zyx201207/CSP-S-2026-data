#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long a[N],n,sum=0;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	long long l=1,r=n,x;
	while(l<r){
		if(a[l]>a[r]){
			x=a[r];
			a[l]-=a[r];
			a[r]=0;
		}
		else {
			x=a[l];
			a[r]-=a[l];
			a[l]=0;
		}
		if(b[l]!=b[r])sum+=x;
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
	}
	cout<<sum;
	return 0;
}
