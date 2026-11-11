#include<iostream>
using namespace std;
int main(){
	int n,b,c=0,a[500001],e,f;
	long long m,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(long long i=1;i<=m;i++){
		s=a[1];
		b=1;
		for(int i=2;i<=n;i++){
			if(a[i]<s){
				s=a[i];
				b=i;
			}
		}
		f=a[b];
		a[b]++;
 	}
	for(int i=1;i<=n;i++){
		s=a[1];
		b=1;
		for(int j=2;j<=n;j++){
			if(a[j]<s && a[j]>f){
				s=a[j];
				b=j;
			}
		}
		f=a[b];
		for(int j=1;i<=n;i++){
			if(a[i]==f){
				e++;
			}
		}
		if(c<e){
			c=e;
		}
 	}
	cout<<c;
	return 0;
} 
