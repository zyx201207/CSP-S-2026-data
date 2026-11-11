#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cot=0,z=0,l=0;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cot+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	cot=cot/2+cot%2;
	for(int i=1,j=0;l<cot;){
		if(c[i]!=c[n-j]){
			if(a[i]>a[n-j]){
				z+=a[n-j];
				l+=a[n-j];
				a[i]-=a[n-j];
				j++;
			}
			else{
				z+=a[i];
				l+=a[i];
				a[n-j]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[n-j]){
				l+=a[n-j];
				a[i]-=a[n-j];
				j++;
			}
			else{
				l+=a[i];
				a[n-j]-=a[i];
				i++;
			}
		}
	}
	cout<<z;
	return 0;
}
