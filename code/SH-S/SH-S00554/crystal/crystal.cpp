#include<bits/stdc++.h> 
using namespace std;
long long n,m,sum,b,flag;
long long a[500000];
int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	
 	cin>>n>>m;
 	for (long long i=0;i<n;i++){
 		cin>>a[i];
	}
	for (long long i=0;i<n-1;i++){
 		if(a[i]>a[i+1]){
 			b=a[i];a[i]=a[i+1];a[i+1]=b;
 			if(i!=0) i=i-2;
		 }
//		 cout<<"i="<<i;
//		 for (int p=0;p<n;p++){cout<<" "<<a[p];}cout<<endl;
	}
//	for (int i=0;i<n;i++){cout<<a[i]<<endl;}
	for (long long i=0;i<n;i++){
//		cout<<"i:"<<i<<endl;
		if((a[i+1]-a[i])*(i+1)<=m){
			m=m-(a[i+1]-a[i])*(i+1);
			for(long long p=0;p<=i;p++){
				a[p]=a[i+1];
			}	
		}
		else {
			flag=i+1;
			break;
		}
//		cout<<"m:"<<m<<endl;
		
	}
	cout<<flag;
	return 0;
 }
