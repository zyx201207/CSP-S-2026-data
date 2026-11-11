#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],z,k,p;
long long s,fhz;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		z+=a[i];
	}
	k=0;
	for(int i=1;;){
			if(n-k-i==0){
				break;
				
			}

		if(a[i]>a[n-k]){
			if(c[i]!=c[n-k])fhz+=a[n-k];
			a[i]-=a[n-k];
			a[n-k]=0;
			k++;
		}
		else{
			
				if(c[i]!=c[n-k])fhz+=a[i];
				a[n-k]-=a[i];
				a[i]=0;
				i++;
			
		}
	}
	cout<<fhz;
	return 0;
}