#include<bits/stdc++.h>
using namespace std;
const int N=2000007;
long long a[N];
char b[N]; 
char c[N];
long long n;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum=sum+a[i];
	}
	long long f=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			c[f]=b[i];
			f=f+1;
		}
	}
	long long mid=sum/2;
	long long ans=0;
	f=f-1;
	for (int i=1;i<=mid;i++){
		if (c[i]!=c[f-i+1]){
			ans=ans+1;
		}
	}
	cout<<ans<<endl; 
	return 0;
}
