#include<bits/stdc++.h> 
using namespace std;
long long n,m=0,sum=0;
char s[100000007];
int y=1;
struct T{
	long long g;
	char z;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	T a[n];
	for(int i=1;i<=n;i++){
	cin>>a[i].g>>a[i].z;
	for(int j=1;j<=a[i].g;j++){
		s[m+j]=a[i].z;
	}
	m+=a[i].g;
	}
	for(int i=1;i<=n-1;i++){
	if(a[i].z!=a[i+1].z){
		y=0;
	}
	}
	if(y){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=m/2;i++){
			if(s[i]!=s[m-i+1]){
			sum++;
		}
	}
	cout<<sum;
}
