#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]=a[i-1]+a[i];
	}
	long long i=a[0],j=a[n];
	int l=1,r=n-1;
	while(l<=r){
		if(a[l]-i<=j-a[r]){
			if(c[l]!=c[r+1])  ans=ans+a[l]-i;
			j=j-(a[l]-i);
			i=a[l];
			l++;
		}
		else{
			if(c[l]!=c[r+1])  ans=ans+j-a[r];
			i=i+(j-a[r]);
			j=a[r];
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
