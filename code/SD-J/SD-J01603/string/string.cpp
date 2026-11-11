#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long sum=0;
	for(int i=1;i<=n;){
		if(n-i==0){
			break;
		}
		if(c[i]!=c[n]){
			if(a[i]>a[n]){
				a[i]=a[i]-a[n];
				sum+=a[n];
				n--;
			}
			if(a[i]<a[n]){
				a[n-i+1]=a[n]-a[i];
				sum+=a[i];
				i++;
			}
			if(a[i]==a[n]&&i<n){
				sum+=a[i];
				i++;
				n--;
			}
		}else{
			if(a[i]>a[n]){
				a[i]=a[i]-a[n];
				n--;
			}
			if(a[i]<a[n]){
				a[n-i+1]=a[n]-a[i];
				i++;
			}
			if(a[i]==a[n]&&i<n){
				i++;
				n--;
			}
		}
	}
	cout<<sum;
	return 0;
} 
