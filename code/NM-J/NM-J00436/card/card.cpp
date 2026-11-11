#include <cstdlib>
#include <iostream>
using namespace std;
long long a[10000001];
long long c[10000001];
long long b[10000001];
int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=10000001;i++){
		c[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0;
	int l=1;
	for(int i=1;i<=n;i++){
		if(a[l]==a[i+1]){
			sum++;
			l++;
		}
	}
	if(sum==0){
		for(int i=1;i<=n;i++){
			cout<<n;
		}
	}
	return 0;
	int y=n;	
	for(int i=0;i<=n;i++){
		b[i]=a[i];
	}
	int u=1;
	int p=1;
	for(int i=n;i>=1;i++){
		for(int d=1;d<=n;d++){
			if(a[u]==a[p+1]){
			a[u]=a[p+1];
			for(int m=u+=1;m<=n;m++){
				a[m]=0;
			}
		}else{
			p++;
		}
		}
	}
	return 0;
	
}
