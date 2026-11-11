#include<bits/stdc++.h>
using namespace std;
int a[1000007];
int b[1000007];
int j=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int num;
	cin>>num;

	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	sort(b,b+n);
	
	for(int i=n-1;i>=0;i--){
		a[j]=b[i];
		j++;
	} 
	int f=a[0];
	for(int i=1;i<num;i++){
		f=f&a[i];
	} 
	cout<<f;
	
	

	return 0;
} 
