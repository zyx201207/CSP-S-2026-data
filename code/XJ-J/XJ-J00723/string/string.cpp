#include<bits/stdc++.h>
using namespace std;

int s[1005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b=0;
	cin>>n;
	string a,c;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int j=0;j<n/2;j++){
		if(c[j]!=c[n-j-1]){
			if(j>a[n-j-1]){
				b+=a[j]-a[n-j-1];
			}
			else{
				b+=a[j]+a[n-j-1]-a[n-j-2];
			}
		}
	}
	cout<<b;
	return 0;
}