#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long sum=0;
	while(l<r){
		if(a[r]>=a[l]){
			if(c[r]!=c[l]) sum+=a[l];
			a[r]-=a[l];
			if(a[r]==0) r--;
			l++;
		}
		else{
			if(c[l]!=c[r]) sum+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<sum;
	return 0;
}