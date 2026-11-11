#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200015];
char b[200015];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	long long sum=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	long long k=0;
	for(long long i=1;i<=n;i++){
		if(i==n){
			cout<<k;
			return 0;
		}
		while(a[i]>=a[n]){
			if(b[i]==b[n]){
				a[i]-=a[n];
				n--;
			}
			else{
				a[i]-=a[n];
				k+=a[n];
				n--;
			}
		}
		if(b[i]==b[n]){
			a[n]-=a[i];
		}
		else{
			a[n]-=a[i];
			k+=a[i];
		}		
	}
	cout<<k;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
