#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]==b[i-1]){
			a[i-1]+=a[i];
			n--;
			i--;
		}
	}
	long long k=0;
	for(long long i=1,j=n;i<=j;){
		if(b[i]!=b[j]){
			if(a[i]>a[j]){
				k+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]==a[j]){
				k+=a[j];
				a[i]=a[j]=0;
				i++;
				j--;
			}
			else{
				k+=a[i];
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]==a[j]){
				a[i]=a[j]=0;
				i++;
				j--;
			}
			else{
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
	}
	cout<<k;
	return 0;
}
