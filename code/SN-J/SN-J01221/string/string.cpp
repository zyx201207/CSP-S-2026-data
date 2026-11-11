#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int s=1;
	for(int i=s;i<=n/2+1;i++){
		if(c[i]==c[n-i+1]){
			if(a[i]>a[n-i+1]){
				a[i]=a[i]-a[n-i+1];
				n--;
			}
			else if(a[i]=a[n-i+1]){
				s++;
				n--;
			}
			else if(a[i]<a[n-i+1]){
				a[n-i+1]=a[n-i+1]-a[i];
				s++;
			}
		}
		if(c[i]!=c[n-i+1]){
			if(a[i]>a[n-i+1]){
				a[i]=a[i]-a[n-i+1];
				sum+=a[n-i+1];
				n--;
			}
			else if(a[i]=a[n-i+1]){
				sum+=a[i];
				s++;
				n--;
			}
			else if(a[i]<a[n-i+1]){
				a[n-i+1]=a[n-i+1]-a[i];
				sum+=a[i]; 
				s++;
			}
		}
	}
	cout<<sum;
	return 0;
}

