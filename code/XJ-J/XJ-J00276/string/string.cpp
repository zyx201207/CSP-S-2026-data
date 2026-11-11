#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
int n;
long long a[MAX];
long long sum=0;
string b[MAX];
string c[MAX];
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	bool flag=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		long long nums=0;
		for(int i=1;i<n/2;i++){
			if(b[i]!=b[n-i]){
				nums+=a[n-i];
			}
		}
		cout<<nums;
		return 0;
	}
	long long l=1;
	for(int i=1;i<=n;i++){
		for(int j=l;j<=a[i]+l-1;j++){
			c[j]=b[i];
		}
		l+=a[i];
	}
	for(int i=1;i<l/2;i++){
		if(c[i]!=c[l-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
