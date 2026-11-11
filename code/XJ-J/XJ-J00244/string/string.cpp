#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],f;
char b[100001];
int j(int x){
	for(int i=x;i<=n;i++){
		a[i]=a[i+1];
		b[i]=b[i+1];
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]){
			a[i]+=a[i+1];
			j(i+1);
			n--;
			i--;
		}
		cout<<i<<" ";
	}
	int h=n;
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[h]||b[i]!=b[h]){
			f+=min(a[i],a[h]);
			cout<<a[i]<<" "<<a[h]<<" ";
		}
		h--;
	}
	cout<<f;
} 

