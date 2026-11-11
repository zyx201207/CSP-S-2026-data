#include<bits/stdc++.h>
using namespace std;//°²Î£Óë 

int n,m;
long long a[10000005];

bool po(long long a,long long b){
	if(a>b){
		return true;
	}
	
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n;
	cin>>m;
	
	

	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);	
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	long long num;
	num=a[n-1];
	
	cout<<num<<endl; 
	

	for(int j=n-2;j>n-m-1;j--){
		
		num=num&a[j];
		cout<<num<<" "<<a[j]<<" ";
		cout<<j<<endl;

	}
	
	cout<<num;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
